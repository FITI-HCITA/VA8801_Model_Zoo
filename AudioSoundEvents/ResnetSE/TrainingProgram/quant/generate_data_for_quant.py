import os, sys
from pathlib import Path
import torchaudio as ta
import torchaudio.functional as F
import pickle
import torch
from torch.nn.utils.rnn import pad_sequence
import numpy as np
import torchaudio.compliance.kaldi as kaldi
import json
from tqdm import tqdm

n_frames = 192

if len(sys.argv) < 2:
    print(f"Usage: {__file__} [out path]")
    sys.exit(1)

src = Path('../dataset/calibration')
out = sys.argv[1]
SR = 8000
n_mels = 24

mels = []

wavs = list(src.glob("**/*.wav"))


for path in tqdm(wavs):
    #
    s, sr = ta.load(path)
    if sr != SR:
        s = F.resample(s, orig_freq=sr, new_freq=SR)
    mel = kaldi.fbank(s, sample_frequency=SR, num_mel_bins=n_mels)
    #
    if mel.size(0) > n_frames:
        mel = mel[:n_frames]
    mel = mel - mel.mean(0, keepdim=True)
    mels.append(mel)
    #
mels = pad_sequence(mels, batch_first=True)
l = n_frames  - mels.size(1)
mels = torch.nn.functional.pad(mels,(0,0,0,l))
mels = mels.numpy()
print('mels shape: ', mels.shape)
np.save(out, mels)
