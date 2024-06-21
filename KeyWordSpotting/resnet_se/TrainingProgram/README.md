## Training program

### 1. Requirement

*Recommendation: Use [anaconda](https://www.anaconda.com/download/success) to manage enviroments*

Install Pytorch

```bash
conda install pytorch torchvision torchaudio pytorch-cuda=11.8 -c pytorch -c nvidia
```

Install requirement for training

```bash
pip install -r requirement_for_training.txt
```

Install requirement for quantization

```bash
pip install -r requirement_for_quant.txt
```

### 2. Data preparation
You can finetune the model with sample data. If you want to use your own data, please read the following steps.
For every label, create two directories under ./dataset/tr and ./dataset/cv and put your training data and validation data under these two directories respectively.
If you want to add more background noise data, put under ./dataset/noise.

the directory tree:

```bash
./dataset
├── cv
│   ├── label_0
│   ├── ...
├── noise
│   ├── noise_1.wav
│   ├── ...
└── tr
    ├── label_0
    │   ├── file_1.wav
    │   ├── file_2.wav
    │   ├── ...
    │   └── file_n.wav
    ├── ...
    └── label_n
```

Note that all data you add should use the extension of wav.

### 3. Model Fine-tuning

```bash
python finetune.py ckpt_name=CKPT_NAME
```

The pytorch model(.pt) will be saved under the path ./ckpt/CKPT_NAME/best.pt

If You want to use the GPU to accelerate the training process, please run:

```bash
python finetune.py ckpt_name=CKPT_NAME device=cuda
```

### 4. Model quantization

```bash
cd quant
```

#### 4-1. Steps of quantization

1. Convert pytorch model to onnx model

```bash
python export_onnx.py --ckpt PATH_TO_PYTORCH_PT_FILE -o PATH_TO_ONNX_MODEL
```

2. Convert onnx model to tensorflow model

```bash
tf2onnx -i PATH_TO_ONNX_MODEL -o PATH_TO_TF_MODEL(directory) -osd
```

3. Generate Data for calibaration of tflite qunatization

```bash
python generate_data_for_tf_quant.py PATH_FOR_SAVING_CALIBRATION_DATA(.npy) sample_rate num_mel_bins
```

4. Convert tensorflow model to tflite model

```bash
python tflite_qunat.py PATH_TO_TF_MODEL(directory) PATH_TO_CALIBRATION_DATA(.npy) PATH_TO_TFLITE_MODEL(.tflite)
```