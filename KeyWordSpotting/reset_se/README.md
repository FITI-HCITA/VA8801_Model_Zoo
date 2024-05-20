# Keyword Spotting

**Version:** 1.001.001

**TrainingProgram:** [TrainingProgram]()

**Category:** Keyword Spotting

**Algorithm:** [ResnetSE](https://github.com/yeyupiaoling/AudioClassification-Pytorch)

**Dataset:** 

**Class:** 'Hi fiti','貨物訊息', 'barcode辨識', '物件辨識'


### Network
|      | Type            | Batch   | Shape      | Remark                                               |
|:---- |:----------------|:-------:|:-----------|:-----------------------------------------------------|
|Input | mel spectrogram |   1     | [192,40]   | number of frames of input should be 192              |
|Output| logits          |   1     | [1,16]     | The output is a 1x16 tensor.                         |

### Benchmark

| Backend      | Precision(%) | MFlops   | Params(K) | Inference(ms) |       Download                                                                                                                                | Author   |
|:------------:|:-------------|:---------|:----------|:-------------:|:----------------------------------------------------------------------------------------------------------------------------------------------|:---------|
|  TFLite-int8 |    99.82     |    20.8  |    62     |       224       |      [link(channel 2)](https://fp-gitlab/hcita/tinyml/va8801_model_zoo/-/blob/develop/KeyWordSpotting(KWS)/resnet_se/KWS_1_001_001.tflite)     | Fitipower|
