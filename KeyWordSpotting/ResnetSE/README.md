# Keyword Spotting

**Version:** 1.001.001

**TrainingProgram:** [TrainingProgram](https://github.com/FITI-HCITA/VA8801_Model_Zoo/tree/main/KeyWordSpotting/ResnetSE/TrainingProgram)

**Category:** Keyword Spotting

**Algorithm:** [ResnetSE](https://github.com/yeyupiaoling/AudioClassification-Pytorch)

**Dataset:** [Sample_Dataset](https://github.com/FITI-HCITA/VA8801_Model_Zoo/tree/main/KeyWordSpotting/reset_se/TrainingProgram/dataset)

**Class:** `Hi fiti`, `貨物訊息`, `barcode辨識`, `物件辨識`


### Network
|      | Type            | Batch   | Shape      | Remark                                               |
|:---- |:----------------|:-------:|:-----------|:-----------------------------------------------------|
|Input | mel spectrogram |   1     | [192,40]   | number of frames of input should be 192              |
|Output| logits          |   1     | [1,16]     | The output is a 1x16 tensor.                         |

### Benchmark

| Backend | Precision(%) | Top-1(%) | MFlops | Params(K) | Inference     | Download | Author |
|:--------|:-------------|:---------|:-------|:----------|:--------------|:---------|:-------|
|  Pytorch     |    FLOAT32   |   99.82  | 20.8 |    62     |       -       |      [link](https://github.com/FITI-HCITA/VA8801_Model_Zoo/tree/main/KeyWordSpotting/ResnetSE/TrainingProgram/KWS_1_001_002.pt) | Fitipower|
|  TFLite      |    INT8      |    99.82 |  -   |    62     |       224     |      [link(shuttle version)](https://github.com/FITI-HCITA/VA8801_Model_Zoo/tree/main/KeyWordSpotting/ResnetSE/KWS_1_001_002.tflite)  | Fitipower|

***Tabel Notes:***
- ***Backend:** The deep learning framework used to infer the model.*
- ***Precision:** The numerical precision used for training the model.*
- ***Inference(ms):** The inference time of the model in milliseconds.*
- ***Link:** The link to the model.*
- ***Author:** The author of the model.*