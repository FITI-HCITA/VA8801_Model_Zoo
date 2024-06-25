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
        self.is_tr = is_tr
        self.sr = config.sr
        self.config = config

        labels = set()

        self.list = []
        print('file parsing...')
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
                    if t <= max_t and t >= min_t:
                        sample = dict(key=str(d.stem), wav=str(path), txt=label)
                        self.list.append(sample)
                        labels.add(label)
                        cnt += 1
                except Exception as e:
                    print(path, e)
            print(f'label name: {d.name}, label index: {idx}, # of files belonging this label: {cnt}')
        assert len(labels) == config.num_label, f'{labels}, {len(labels)} vs {config.num_label}'
        #
        self.add_noise = config.augment.noise.add
        self.noises = list( Path(config.augment.noise.path).glob("**/*.wav"))

        self.noise_freq = config.augment.noise.freq

    def load_wav(self, path):
        s, sr = ta.load(path)
        if s.size(0) > 1:
            s = s.mean(dim=0, keepdim=True)
        if sr != self.sr:
            s = ta.functional.resample(s, orig_freq=sr, new_freq=self.sr)
        return s

    def Meler(self, s):
        config = self.config
        mel = kaldi.fbank(
                s, frame_length=1000*config.fft.frame_t, frame_shift=1000*config.fft.stride_t, sample_frequency=config.sr,
                num_mel_bins=config.fft.n_mel)
        return mel

    def noise_perturb(self, s):
        if np.random.uniform(0, 1) > self.noise_freq:
            return s
        #
        noise_path = np.random.choice(self.noises)
        noise = self.load_wav(noise_path)
        #
        if noise.size(1) > s.size(1):
            beg = np.random.randint(0, noise.size(1) - s.size(1))
            end = beg + s.size(1)
            n = noise[:, beg:end]
        elif noise.size(1) < s.size(1):
            num = int(s.size(1) / noise.size(1)) + 1
            n = noise.repeat(1, num)
            n = n[:,:s.size(1)]
        else:
            n = noise
        #
        snr = np.random.randint(10, 50)

        rmss = (s**2).mean(dim=1)**0.5
        rmsn = (n**2).mean(dim=1)**0.5

        scale = rmss / (10**(snr/20) * rmsn + 1e-12)


        n *= scale
        rmsn = (n**2).mean(dim=1)**0.5
        tmp = snr
        snr = 20 * torch.log10(rmss/(1e-12+rmsn) + 1e-10)

        x = s + n

        return x

    def __len__(self):
        return len(self.list)

    def __getitem__(self, idx):
        sample = self.list[idx]
        # key, duration, txt, wav
        s = self.load_wav(sample['wav'])

        speed = np.random.choice([0.9, 1.0, 1.1])
        if speed != 1:
            s = s.squeeze().numpy()
            s = lr.effects.time_stretch(s, rate=speed)
            s = torch.from_numpy(s).view(1, -1)
            #s, _ = ta.sox_effects.apply_effects_tensor(s, self.sr,[
            #    ['speed', str(speed)],
            #    ['rate', str(self.sr)],
            #    ])

        #
        if self.add_noise == True and self.is_tr and \
                sample['txt'] != 0:
            #
            s = self.noise_perturb(s)
        #
        norm = s.abs().mean()
        if norm >= 1e-9:
            s = s/norm
        s = s * np.random.uniform(self.config.augment.min_val, 1)
        #
        # mel spectrogram
        mel = self.Meler(s) # [n_mel, T]
        #mel = torch.log(mel + 1e-7)
        # [T, n_mel]

        if self.config.normalize:
            mel = mel - mel.mean(dim=0, keepdim=True)

        # spec aug
        if self.is_tr and sample['txt'] != 0:
            mel = self.spec_aug(mel)
        return dict(key=sample['key'],
                    label=int(sample['txt']),
                    feat=mel)
    
    def spec_aug(self, x):
        #v num_t_mask, num_f_mask, max_t, max_f
        y = x.clone().detach()
        T, F = x.size()

        # frame
        bandwidth = int(self.config.augment.bandmask * self.config.fft.n_mel)
        if bandwidth == 0:
            return x
        start = np.random.randint(0, F)
        end = min(F, start + bandwidth)

        y[:, start:end] *= np.random.uniform(0, 1e-6)
        return y
