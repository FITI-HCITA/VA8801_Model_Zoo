import torch
import sys
import torch.nn as nn
import torch.nn.functional as F
import torchaudio as ta
from torch.utils.data import Dataset
from pathlib import Path
import numpy as np
import math
import soundfile as sf
from tqdm import tqdm
import json
import torchaudio as ta
import random
import torchaudio.compliance.kaldi as kaldi



class AudioData(Dataset):
    def __init__(self, src, config, dry_run=False, is_tr=True):
        super(AudioData, self).__init__()
        #
        max_t = config.max_t
        min_t = config.min_t
        self.max_t = max_t
        self.is_tr = is_tr
        self.sr = config.sr
        self.config = config

        labels = set()

        self.list = []
        print('file reading...')
        #####
        ds = []
        for d in Path(src).iterdir():
            wavs = list(d.glob("**/*.wav"))
            if len(wavs) > 0:
                ds.append(d)
        ds.sort()
        for idx, d in enumerate(ds):
            wavs = list(d.glob("**/*.wav"))
            label = idx
            cnt = 0
            for path in wavs:
                path = str(path)
                try:
                    info = ta.info(path)
                    t = info.num_frames / info.sample_rate
                    if t < min_t and is_tr:
                        continue
                    tmp = dict(wav=path, key=Path(path).stem, duration=t, txt=label)
                    self.list.append(tmp)
                    labels.add(label)
                    cnt += 1
                except Exception as e:
                    print(path, e)
            print(f'label name: {d.name}, label index: {idx}, # of files belonging this label: {cnt}')
        assert len(labels) == config.num_label, f'{labels}, {len(labels)} vs {config.num_label}'
        #
        print('load noise...')
        self.noise_freq = config.augment.noise.freq
        self.noise_list = list(Path(config.augment.noise.path).glob("**/*.wav"))

    def noise_perturb(self, s):
        if np.random.uniform(0, 1) > self.noise_freq:
            return s
        # snr: 10 ~ 50
        noise_path = np.random.choice(self.noise_list)
        noise, sr = ta.load(noise_path)
        # resample
        if sr != self.sr:
            noise = ta.functional.resample(noise, orig_freq=sr, new_freq=self.sr)
        # sample snr
        snr = np.random.uniform(10, 50)
        # crop or pad
        if noise.size(1) > s.size(1):
            beg = np.random.randint(0, noise.size(1) - s.size(1))
            end = beg + s.size(1)
            n = noise[:, beg:end]
        elif noise.size(1) < s.size(1):
            num = int(s.size(1)/noise.size(1))+1
            noise = noise.repeat(1, num)
            n = noise[:, :s.size(1)]
        else:
            n = noise
        #
        n_db = 10*torch.log10( n.pow(2).mean() + 1e-7)
        s_db = 10*torch.log10( s.pow(2).mean() + 1e-7)
        # snr = s_db - (n_db + gain)
        n_gain_db = torch.clamp(s_db - n_db - snr, max=300)
        n = n * 10**(n_gain_db/20)
        x = s + n
        norm = x.abs().max()
        if norm > 1:
            x = x/norm
        return x

    def __len__(self):
        return len(self.list)

    def __getitem__(self, idx):
        sample = self.list[idx]
        # key, duration, txt, wav
        s, sr = ta.load(sample['wav'])
        if s.size(0) > 1:
            s = s.mean(dim=0, keepdim=True)
        # resample
        if sr != self.sr:
            s = ta.functional.resample(s, orig_freq=sr, new_freq=self.sr)

        # augment: [speed, add noise]
        if self.is_tr:
            # speed
            speed = np.random.choice([0.9, 1.0, 1.1])
            if speed != 1.0:
                s, _ = ta.sox_effects.apply_effects_tensor(s, self.sr,[
                    ['speed', str(speed)],
                    ['rate', str(self.sr)],
                    ])
            # add noise
            s = self.noise_perturb(s)
        # crop
        if s.size(1) / self.sr > self.max_t:
            l = int(self.sr * self.max_t)
            s = s[:,:l]

        # mel spectrogram
        mel = self.Meler(s)

        # spec aug
        if self.is_tr:
            if self.config.augment.spec_aug.apply:
                mel = self.spec_aug(mel)

        return dict(key=sample['key'],
                    label=int(sample['txt']),
                    feat=mel)

    def Meler(self, s):
        config = self.config

        mel = kaldi.fbank(s, sample_frequency=config.sr, num_mel_bins=config.fft.n_mel)
                #s, frame_length=1000*config.fft.frame_t, frame_shift=1000*config.fft.stride_t, sample_frequency=config.sr,
                #num_mel_bins=config.fft.n_mel)
        # mel: [t, num_mel]
        mel = mel - mel.mean(0, keepdim=True)
        return mel
    def spec_aug(self, x):
        config = self.config.augment.spec_aug
        # x: [t, f]
        T, F = x.size()
        # time
        beg = np.random.randint(0, T)
        bw = np.random.randint(config.time_mask_width[0], config.time_mask_width[1])
        end = min(beg+bw, T)
        x[beg:end,:] *= np.random.uniform(0, 1e-6)
        # freq
        beg = np.random.randint(0, F)
        bw = np.random.randint(config.freq_mask_width[0], config.freq_mask_width[1])
        end = min(beg+bw, F)
        x[:,beg:end] *= np.random.uniform(0, 1e-6)

        return x
