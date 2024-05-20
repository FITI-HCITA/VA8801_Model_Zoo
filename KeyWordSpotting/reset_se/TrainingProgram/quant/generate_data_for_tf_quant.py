import os, sys
from pathlib import Path
import torchaudio as ta
import torchaudio.functional as F
import pickle
import torch
from torch.nn.utils.rnn import pad_sequence
import numpy as np
import torchaudio.compliance.kaldi as kaldi

#SR = 16000

if len(sys.argv) < 5:
    print(f"Usage: {__file__} [path to folder containing inp wav files] [path to save out data(*.npy)] [sr] [n_mel]")
    sys.exit(1)
src = Path(sys.argv[1])
out = sys.argv[2]
SR = int(sys.argv[3])
n_mel = int(sys.argv[4])

mels = []
wavs = list(src.glob('**/*.wav'))
print(len(wavs))

for w in wavs:
    s, sr = ta.load(w)
    if sr != SR:
        s = F.resample(s, orig_freq=sr, new_freq=SR)
    mel = kaldi.fbank(
            s, frame_length=25, frame_shift=10,
             num_mel_bins=n_mel, sample_frequency=SR) #, remove_dc_offset=False)
    #mel = torch.log(mel + 1e-7) # [n, 24]
    mel = mel - mel.mean(dim=0, keepdims=True)
    if mel.size(0) > 192:
        mel = mel[:192]
    mels.append(mel)

mels = pad_sequence(mels, batch_first=True)
# [b, l, 24]
l = 192  - mels.size(1)
mels = torch.nn.functional.pad(mels,(0,0,0,l))
#
mels = mels.numpy()
np.save(out, mels)