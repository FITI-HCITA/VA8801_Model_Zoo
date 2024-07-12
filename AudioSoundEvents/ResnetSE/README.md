# Audio Sound Events

**Version:** 1.001.000

**TrainingProgram:** [TrainingProgram](https://github.com/FITI-HCITA/VA8801_Model_Zoo/tree/main/AudioSoundEvents/ResnetSE/TrainingProgram)

**Category:** Audio Sound Events

**Algorithm:** [ResnetSE](https://github.com/yeyupiaoling/AudioClassification-Pytorch)

**Dataset:** [Sample dataset](https://github.com/FITI-HCITA/VA8801_Model_Zoo/tree/main/AudioSoundEvents/ResnetSE/TrainingProgram/dataset)

**Class:** `Background noise`,`Baby crying`, `Glass breaking`, `Gun shot`


### Network
|      | Type            | Batch   | Shape      | Remark                                               |
|:---- |:----------------|:-------:|:-----------|:-----------------------------------------------------|
|Input | mel spectrogram |   1     | [192,24]   | number of frames of input should be 192              |
|Output| logits          |   1     | [1,4]      | The output is a 1x4 tensor.                          |

### Benchmark

| Backend | Precision | Top-1(%) | MFlops | Params(K) | Inference | Download | Author |
|:-------:|:----------|:---------|:-------|:---------:|:----------|:---------|:-------|
| Pytorch |  FLOAT32  |    97.80 |  20.8  |    62     |           | [link](https://github.com/FITI-HCITA/VA8801_Model_Zoo/tree/main/AudioSoundEvents/ResnetSE/TrainingProgram/AudioSoundEvent_1_001_000.pt) | Fitipower |
|  TFLite |  int8     |    97.80 |   -    |    62     |       129 | [link(shuttle version)](https://github.com/FITI-HCITA/VA8801_Model_Zoo/tree/main/AudioSoundEvents/ResnetSE/AudioSoundEvent_1_001_000.tflite) | Fitipower |

***Tabel Notes:***
- ***Backend:** The deep learning framework used to infer the model.*
- ***Precision:** The numerical precision used for training the model.*
- ***Inference(ms):** The inference time of the model in milliseconds.*
- ***Link:** The link to the model.*
- ***Author:** The author of the model.*