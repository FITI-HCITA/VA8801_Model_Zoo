# VA8801 Model Zoo

<div align="center">
  <a href="https://www.fitipower.com/" target="_blank"><img width="20%" src="https://www.fitipower.com/files/images/index/img02.webp"></a>
</div>

[English](README.md) | [繁體中文](README_zh_TW.md) |简体中文

## 简介

欢迎来到 Fitipower VA8801 Model Zoo。我们针对不同的应用场景，提供了一系列预训练的模型供您使用，配合 [Fitipower VA8801 SDK](https://www.fitipower.com/)開發環境，您可以对这些模型进行测试和推理，并轻松地部署到边缘计算设备上。

VA8801 Model Zoo 专注于提供在 VA8801 优化的神经网络上训练得到的模型，这些模型针对现实应用场景，能够在嵌入式设备上实现更快和更准确的推理。

<br>标准模型格式tflite INT8量化檔.
<br>使用Fitipower VA8801 天元编译程序 

## 应用场景
目前，VA8801 Model Zoo 提供如下应用场景的预训练模型:
<br>AudioDenoise - 語音去躁 
<br>AudioSoundEvents - 異常聲音檢測
<br>AudioSpeechRecognition - 語音識別
<br>ClassicalModels - 經典模型
<br>DualVisionDepth - 雙目深度
<br>FaceOrientation - 人臉方位
<br>FaceRecognition - 人臉識別
<br>KeyWordSpotting - 關鍵詞
<br>ObjectDetection - 物件偵測
<br>SpeakerVertification - 語者識別                                                     

如果您需要特定场景下特定数据集的预训练模型，欢迎向我们[提交 Issues]。

## 快速上手

如果您希望使用 VA8801 Model Zoo 提供的模型，我们建议您遵循以下步骤:

1. 根据实际需求，选择相应的应用场景并挑选合适的神经网络。您可以浏览我们给出的测试数据进行选择。
2. 下载选择好的模型。对于公开的预训练模型，您可以通过测试数据表格中的模型链接直接下载。
3. 参考 [VA8001 SDK 文档 - 部署示例](https://www.fitipower.com/)在边缘计算设备上进行部署。您也可以使用 VA8801 在您的计算机上运行我们的模型，对我们的测试结果进行复现或推理测试。

## 故障排除

如果您在使用 VA8801 Model Zoo 中预训练模型时遇到任何问题，请向我们[提交 Issues](https://www.fitipower.com/)。

## 开源许可证

不同的神经网络、数据集和模型受不同的开园许可证保护，具体请参考 [LICENSES](LICENSES)。