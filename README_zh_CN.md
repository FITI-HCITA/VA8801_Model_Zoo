# VA8801 Model Zoo

<div align="center">
  <a href="https://www.fitipower.com/" target="_blank"><img width="20%" src="https://www.fitipower.com/files/images/index/img02.webp"></a>
</div>

[English](README.md) | [繁體中文](README_zh_TW.md) |简体中文

## 介绍

欢迎来到 Fitipower VA8801 Model Zoo。
VA8801是俱备高运算力且极低功耗的自主开发的边缘运算神经网路晶片,擅长处理语音/影像及各种感测器资料(Sensor Fusion). 在主AP还未唤醒前以Sensor Hub的 角色在极低功耗实时(always-on)感测及预处理环境讯息.必要时才将AP唤醒以降低系统功耗。

VA8801除内建硬体化各种讯号处理运算处理(ISP/DSP) 并配置先进人工智慧神经网路加速器执行各式AI模型(人脸侦测/物件侦测/语音侦测)并应用于各类 终端产品并使其智慧化.特别是电池供电类产品(Doorbell/IPcam..)。 

我们针对不同的应用场景，提供了一系列预先训练的模型供您使用，配合Fitipower VA8801 SDK开发环境，您可以对这些模型进行测试和推理，并轻松地部署到VA8801上。 [联系我们](mailto:support.ai@fitipower.com?subject=SDK)。

VA8801 Model Zoo 专注于提供在 VA8801 优化的神经网路上训练所得的模型，这些模型针对现实应用场景，能够在VA8801上实现更快和更准确的推理。 我们会陆续推出更多优化兼容模型。

<br>标准模型格式tflite INT8量化档。
<br>使用Fitipower VA8801 AI compiler(Tengen)编译模型转换成C code代码。

## 应用场景
目前，VA8801 Model Zoo 提供以下应用场景的预训练模型:
<br>AudioSoundEvents - 异常声音检测
<br>ClassicalModels - 经典模型
<br>KeyWordSpotting - 关键词
<br>ObjectDetection - 物件侦测                                                    

如果您需要特定场景下特定资料集的预训练模型，欢迎向我们[提交 Issues](mailto:support.ai@fitipower.com?subject=ISSUE)。

## 快速上手

如果您希望使用 VA8801 Model Zoo 提供的模型，我们建议您遵循以下步骤:

1. 根据实际需求，选择相应的应用场景并挑选合适的神经网路。  您可以浏览我们给出的测试数据进行选择。
2. 下载选择好的模型。  对于公开的预训练模型，您可以透过测试资料表中的模型连结直接下载。
3. 参考 VA8001 SDK 文件 - 部署范例在VA8801上进行部署。您也可以使用 VA8801上运行我们的模型，对我们的测试结果进行复现或推理测试。 [联系我们](mailto:support.ai@fitipower.com?subject=SDKDEV&body=Please%20share%20SDK%20to%20us.)。

## 故障排除

如果您在使用 VA8801 Model Zoo 中预训练模型时遇到任何问题，请向我们[提交 Issues](mailto:support.ai@fitipower.com?subject=ISSUE)。

## 开源许可证

不同的神经网路、资料集和模型受不同的开源许可证保护，具体请参考 [LICENSES](LICENSES)。