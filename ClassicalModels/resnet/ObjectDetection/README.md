# Fruit ESL - ResNet

**Version:** 2.001.001

**Category:** Object Detection

**TrainingProgram:** [ResNet](https://github.com/FITI-HCITA/yolov5/tree/Resnet_VA8801)

**Algorithm:** [ResNet](https://github.com/FITI-HCITA/yolov5/blob/Resnet_VA8801/models/resnet50.yaml)

**Dataset:** ESL

**Class:** (0)Orange, (1)Apple, (2)Banana, (3)Durian, (4)Broccoli, (5)Tomato, (6)Pineapple, (7)Pitaya, (8)Strawberry, (9)Grape

<div align="center">
    <a href="./">
        <img src="./ESL_ResNet.jpg" width="50%"/>
    </a>
</div>

### Supported VA8801 Version

| Format | VA8801 Shuttle  |
| --- | --- |
| TFLite - INT8 | ✅ |


### Network

|	    |  Type	| Batch	| Shape        | Remark                                                           |
|:------|:------|:------|:-----------  |:-----------------------------------------------------------------|
| Input | image |   1   | [320,320,3]  | The input image should be resized to 96x96x1                     |
| Output| bbox  |   1   | [1500,15]    | The output is a 1500x15 tensor, 1500 is the number of candidates |


### Benchmark

| Backend      | Precision(%) | Recall(%) | GFlops   | Params(K) | Inference(ms) |   Download                                                                                                                                     | Author   |
|:------------:|:-------------|:----------|:---------|:----------|:-------------:|:-----------------------------------------------------------------------------------------------------------------------------------------------|:---------|
|  TFLite-int8 |    96.30     |    91.50  |    ---   |    769    |     -         | [link](https://github.com/FITI-HCITA/VA8801_Model_Zoo/blob/main/ClassicalModels/resnet/ObjectDetection/ResNet_2.001.001.tflite)             | Fitipower|

***Table Notes:***

- ***Evaluation Parameters:** Confidence Threshold: 0.5, IoU Threshold: 0.45
- ***Backend:** The deep learning framework used to infer model.*
- ***Inference(ms):** The inference time of the model in milliseconds.*
- ***Author:** The author of the model.*
