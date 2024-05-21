# Audio Sound Events

**Version:** 1.001.000

**TrainingProgram:** [TrainingProgram]()

**Category:** Audio Sound Events

**Algorithm:** [ResnetSE](https://github.com/yeyupiaoling/AudioClassification-Pytorch)

**Dataset:** 

**Class:** 'Background noise','Baby crying', 'Glass breaking', 'Gun shot'


### Network
|      | Type            | Batch   | Shape      | Remark                                               |
|:---- |:----------------|:-------:|:-----------|:-----------------------------------------------------|
|Input | mel spectrogram |   1     | [192,24]   | number of frames of input should be 192              |
|Output| logits          |   1     | [1,4]      | The output is a 1x4 tensor.                          |

### Benchmark

| Backend      | Precision(%) | MFlops   | Params(K) | Inference(ms) |       Download                                                                                                                                | Author   |
|:------------:|:-------------|:---------|:----------|:-------------:|:----------------------------------------------------------------------------------------------------------------------------------------------|:---------|
|  TFLite-int8 |    97.80     |    20.8  |    62     |       224       |      [link(shuttle version)](https://fp-gitlab/hcita/tinyml/va8801_model_zoo/-/blob/develop/AudioSoundEvents/ResnetSE/AudioSoundEvent_1_001_000.tflite)     | Fitipower|
