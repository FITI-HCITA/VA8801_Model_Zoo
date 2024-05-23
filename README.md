# VA8801 Model Zoo
<div align="center">
  <a href="https://www.fitipower.com/" target="_blank"><img width="20%" src="https://www.fitipower.com/files/images/index/img02.webp"></a>
</div>

English | [繁體中文](README_zh_TW.md) | [简体中文](README_zh_CN.md)

## Introduction
Welcome to VA8801 Model Zoo. 

VA8801 is a self-developed edge computing neural network chip with high computing power and extremely low power consumption. It is good at processing voice/image and various sensor data (Sensor Fusion). Before the main AP wakes up, use Sensor Hub The role is to sense and preprocess environmental information in real-time (always-on) with extremely low power consumption. The AP will be woken up only when necessary to reduce system power consumption.

In addition to built-in hardware for various signal processing operations (ISP/DSP), VA8801 is equipped with an advanced artificial intelligence neural network accelerator to execute various AI models (face detection/object detection/voice detection) and be used in various applications. similar terminal products and make them smart. Especially battery-powered products (Doorbell/IPcam..).

We provide a series of pre-trained models for different application scenarios for you to use, with Fitipower VA8801 SDK, you can test or inference on these models and easily deploy them to VA8801 device.[Contect Us](mailto:support.ai@fitipower.com?subject=SDK).

VA8801 Model Zoo focuses on providing models trained on VA8801 optimized neural networks, which are tailored to real-world application scenarios and enable faster and more accurate inference on VA8801 device. We will provide more models later.

<br>  Standard model format is INT8 tflite.
<br>  Using Fitipower Tengen Compiler for VA8801

## Application Scenarios

  Currently, VA8801 Model Zoo provides pre-trained models for the following application scenarios:
<br>  AudioSoundEvents - Abnormal sound detection
<br>  ClassicalModels - Classical Models
<br>  KeyWordSpotting - Key word spotting
<br>  ObjectDetection - Object detection


## Quickly Start

If you wish to use the model provided by VA8801 Model Zoo, we recommend that you follow the following steps:

1. Based on actual needs, select corresponding application scenario and choose appropriate neural networks. You can browse the test results that we provide for dicision.
2. Download the selected pre-trained model. For public pre-trained models, you can directly download them through the model link in the test results table.
3. Please refer to VA8801 SDK Documentation - Deployment Example to deploy on our devices. [Contect Us](mailto:support.ai@fitipower.com?subject=SDK).

## Troubleshooting

If you encounter any problem with pre-trained models in VA8801 Model Zoo, please write [email](mailto:support.ai@fitipower.com?subject=ISSUE) to us.


## License

Different neural networks, datasets, and models are protected by different licenses, please refer to the [LICENSES](LICENSES) for detailed permissions and restrictions.
