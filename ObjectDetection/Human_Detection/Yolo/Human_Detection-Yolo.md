# Human Detection - Yolo

**Version:** 6.001.001

**Category:** Object Detection

**Algorithm:** [Yolov5](https://fp-gitlab/hcita/tinyml/va8801_model_zoo/-/tree/main/ObjectDetection(OD)/Human_Detection/Yolo/opt.yaml)

**Dataset:** COCO-human,surveillance,cctv-fitipower

**Class:** Human

![Human Detection](https://fp-gitlab/hcita/tinyml/va8801_model_zoo/-/tree/main/ObjectDetection(OD)/Human_Detection/Yolo/Human_Detection-Yolo.png)

### Network

|	    |  Type	| Batch	| Shape      | Remark                                                         |
|:------|:------|:------|:-----------|:---------------------------------------------------------------|
| Input | image |   1   | [96,96,1]  | The input image should be resized to 96x96x1                   |
| Output| bbox  |   1   | [567,6]    | The output is a 576x6 tensor, 576 is the number of candidates  |


### Benchmark

| Backend      | Precision(%) | Recall(%) | GFlops   | Params(K) | Inference(ms) |       Download                                                                                                                                | Author   |
|:------------:|:-------------|:----------|:---------|:----------|:-------------:|:----------------------------------------------------------------------------------------------------------------------------------------------|:---------|
|  TFLite-int8 |    95.30     |    90.20  |    0.5   |    120    |       -       |      [link](https://fp-gitlab/hcita/tinyml/va8801_model_zoo/-/tree/main/ObjectDetection(OD)/Human_Detection/Yolo/HUMAN_DET_6_001_001.tflite)  | Fitipower|

***Table Notes:***

- ***Evaluation Parameters:** Confidence Threshold: 0.6, IoU Threshold: 0.45
- ***Backend:** The deep learning framework used to infer model.*
- ***Inference(ms):** The inference time of the model in milliseconds.*
- ***Author:** The author of the model.*