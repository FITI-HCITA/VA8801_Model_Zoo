## Training program

### 1. Requirement

*Recommendation: Use [anaconda](https://www.anaconda.com/download/success) to manage enviroments*
* Python 3.9

Install environment

```bash
conda create -n kws python=3.9
```

Activate environment
```bash
conda activate kws
```

Install Pytorch

```bash
conda install pytorch torchvision torchaudio pytorch-cuda=11.8 -c pytorch -c nvidia
```

Install requirements

```bash
pip install -r requirements.txt
```

```bash
sudo apt install libsox-dev
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
python finetune.py ckpt_name=KWS
```

The pytorch model(.pt) will be saved under the path ./ckpt/KWS/best.pt

If You want to use the GPU to accelerate the training process, please run:

```bash
python finetune.py ckpt_name=KWS device=cuda
```

### 4. Model quantization

```bash
cd quant
```

#### 4-1. Steps of quantization

1. Convert pytorch model to onnx model

```bash
python export_onnx.py --ckpt ../ckpt/KWS/best.pt -o kws.onnx
```

2. Convert onnx model to tensorflow model

```bash
onnx2tf -i kws.onnx -o ./saved_model -osd -n
```

3. Generate Data for calibaration of tflite qunatization

```bash
python generate_data_for_tf_quant.py ./data.npy
```

4. Convert tensorflow model to tflite model

```bash
python tflite_quant.py ./saved_model ./data.npy kws.tflite
```

The generated tflite model will be under the path:
    `TrainingProgram/quant/kws.tflite.`