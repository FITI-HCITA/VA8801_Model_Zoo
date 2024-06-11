# Audio Sound Events

**Version:** 1.001.000

**TrainingProgram:** [TrainingProgram](https://github.com/FITI-HCITA/VA8801_Model_Zoo/tree/main/AudioSoundEvents/ResnetSE/TrainingProgram)

**Category:** Audio Sound Events

**Algorithm:** [ResnetSE](https://github.com/yeyupiaoling/AudioClassification-Pytorch)

**Dataset:** 

**Class:** `Background noise`,`Baby crying`, `Glass breaking`, `Gun shot`


### Network
|      | Type            | Batch   | Shape      | Remark                                               |
|:---- |:----------------|:-------:|:-----------|:-----------------------------------------------------|
|Input | mel spectrogram |   1     | [192,24]   | number of frames of input should be 192              |
|Output| logits          |   1     | [1,4]      | The output is a 1x4 tensor.                          |

### Benchmark

| Backend | Precision | Top-1(%) | MFlops | Params(K) | Inference | Download | Author |
|:-------:|:----------|:---------|:-------|:---------:|:----------|:---------|:-------|
| Pytorch |  FLOAT32  |    97.80 |  20.8  |    62     |       224 | [link](https://github.com/FITI-HCITA/VA8801_Model_Zoo/tree/main/AudioSoundEvents/ResnetSE/AudioSoundEvent_1_001_000.tflite) | Fitipower |
|  TFLite |  FLOAT32  |    97.80 |   -    |    62     |       224  | [link(shuttle version)](https://github.com/FITI-HCITA/VA8801_Model_Zoo/tree/main/AudioSoundEvents/ResnetSE/AudioSoundEvent_1_001_000.tflite) | Fitipower |
