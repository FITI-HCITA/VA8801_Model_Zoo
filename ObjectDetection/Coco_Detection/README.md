# Pose_Estimation_Yolo_320

**Version:** 2.001.001

**Category:** Pose Estimation

**TrainingProgram:** [Yolov8 v8.1.0](https://github.com/ultralytics/ultralytics/tree/main) 

**Algorithm:** [Yolov8 v8.1.0](https://github.com/ultralytics/ultralytics/tree/main)

**Dataset:** COCO dataset

**Class:** 80 objects

The model is a YOLOv8 object detection model trained on the Opensource COCO dataset.

### Supported VA8801 Version

| Format | VA8801 Shuttle  |
| --- | --- |
| TFLite - INT8 | ✅ |

### Network

|  | Type | Batch | Shape | Remark |
| --- | --- | --- | --- | --- |
| Input | image | 1 | [320, 320, 3] | The input image should be resized to 320x320x3 pixels. |
| Output | bbox | 1 | [1, 84, 2100] | The output is a 1x84x2100 tensor, 2100 is the number of candidates |

### Benchmark

| Backend | mAP50 | Flops(B) | Params(M) | Inference(ms) | Download | Author |
| --- | --- | --- | --- | --- | --- | --- |
| pytorch | 96.4 | 9.2 | 3.1 | - | - | ultralytics |
| TFLite - INT8 | - | - | 3.1 | 429 | [link](./yolov8n_2_001_001.tflite) | ultralytics |

***Table Notes:***

- ***Backend:** The deep learning framework used to infer the model.*
- ***mAP50-pose:** The mean Average Precision at a 50% Intersection Over Union (IoU) threshold for pose estimation.*
- ***Inference(ms):** The inference time of the model in milliseconds.*
- ***Link:** The link to the model.*
- ***Author:** the author of the model.*

---

