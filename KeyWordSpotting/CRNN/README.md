# Keyword Spotting

**Version:** 2_001_002

**TrainingProgram:** [TrainingProgram]()

**Category:** Keyword Spotting

**Algorithm:** [CRNN](https://arxiv.org/pdf/1703.05390)

**Dataset:** [Fitipower_Dataset]

**Class:** `你好方方`, `Hi方方`, `打開屏幕`, `關閉屏幕`, `關閉防窺`, `打開防窺`, `關閉節能`, `打開節能`


### Network
|      | Type            | Batch   | Shape      | Remark                                               |
|:---- |:----------------|:-------:|:-----------|:-----------------------------------------------------|
|Input | mel spectrogram |   1     | [88,24]    | The number of frames of input is 192.                |
|Output| logits          |   1     | [1,17]     | The output is a 1x16 tensor.                         |

### Benchmark

| Backend | Precision(%) | Top-1(%) | MFlops | Params(K) | Inference     | Download | Author |
|:--------|:-------------|:---------|:-------|:----------|:--------------|:---------|:-------|
|  Tensorflow  |    FLOAT32   |   99     | 2.4  |    39     |       -       |      [link](https://fp-gitlab/hcita/tinyml/va8801_model_zoo/-/tree/main/KeyWordSpotting/CRNN/KWS_2_001_002) | Fitipower|
|  TFLite      |    INT8      |   98     |  -   |    39     |       -       |      [link(shuttle version)](https://fp-gitlab/hcita/tinyml/va8801_model_zoo/-/blob/main/KeyWordSpotting/CRNN/KWS_2_001_002.tflite)  | Fitipower|

***Tabel Notes:***
- ***Backend:** The deep learning framework used to infer the model.*
- ***Precision:** The numerical precision used for training the model.*
- ***Inference(ms):** The inference time of the model in milliseconds.*
- ***Link:** The link to the model.*
- ***Author:** The author of the model.*