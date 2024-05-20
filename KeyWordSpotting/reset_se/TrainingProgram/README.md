## Training program

### Requirement

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

### Data preparation
Prepare 3 txt files, tr_data.txt, val_data.txt and noise_file.txt.
tr_data.txt ands val_data.txt contain training data and validation data respectively. Format of these two files are:  

    path_to_file_1 label_of_file_1
    path_to_file_2 label_of_file_2
    ...
    path_to_file_n label_of_file_n

Note: There is a blank separating "path_to_file_n" and "label_of_file_n".

noise_file.txt contains the paths of noise files using for data augmentation.

### Model training

```bash
python train.py tr=path_to_tr_data.txt cv=path_to_val.txt augment.noise.path=path_to_noise_file.txt ckpt_name=CKPT_NAME
```

The pytorch model will be saved under the path ./ckpt/CKPT_NAME/best.pt

### Model quantization

```bash
cd quant
```

#### Steps of quantization

1. Convert pytorch model to onnx model

```bash
python export_onnx.py --ckpt PATH_TO_PYTORCH_PT_FILE -o PATH_TO_ONNX_MODEL
```

2. Convert onnx model to tensorflow model

```bash
tf2onnx -i PATH_TO_ONNX_MODEL -o PATH_TO_TF_MODEL -osd
```

3. Generate Data for calibaration of tflite qunatization

```bash
python generate_data_for_tf_quant.py SRC_FOLDER PATH_TO_OUTPUT_DATA sample_rate num_mel_bins
```

SRC_FOLDER: path to the folder that contains wav files for calibration
PATH_TO_OUTPUT_DATA: path for saving output data(.npy)

4. Convert tensorflow model to tflite model

```bash
python tflite_qunatization.py PATH_TO_TF_MODEL PATH_TO_OUTPUT_DATA PATH_TO_TFLITE_MODEL
```