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

n_mels = 24
n_frames = 192

if len(sys.argv) < 5:
    print(f"Usage: {__file__} [src] [out path] [label out path] [sr]")
    sys.exit(1)

src = Path(sys.argv[1])
out = sys.argv[2]
label_out = sys.argv[3]
SR = int(sys.argv[4])

mels = []
labels = []

with open(src, 'r') as f:
    lists = f.readlines()

print(len(lists))

for line in tqdm(lists):
    obj = json.loads(line.rstrip())
    path = obj['path']
    label = obj['label']
    #
    labels.append(label)
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
#
mels = mels.numpy()
print('mels shape: ', mels.shape)
np.save(out, mels)
#
labels= np.array(labels)
np.save(label_out,labels)
