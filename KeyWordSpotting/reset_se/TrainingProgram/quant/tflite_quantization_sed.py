import os
import argparse
import numpy as np
import tensorflow as tf
import tensorflow_model_optimization as tfmot
import sys

class Dataloader():
    def __init__(self, path):
        self.data = np.load(path).astype(np.float32)

    def __len__(self):
        return len(self.data)

    def __getitem__(self, index):
        return self.data[index]

def convert_to_tflite_quant(pb_folder_path, data_path, cal_dataset_folder_path=None, train_data=None, train_labels=None, mode=0):
    def representative_dataset():
        cal_dataset = Dataloader(data_path)
        valid_cnt = 0
        print(f'num of calibration data: {len(cal_dataset)}')
        for idx in range(len(cal_dataset)):
            input_data = cal_dataset[idx]
            input_data = np.expand_dims(input_data, axis=0)
            input_data = np.transpose(input_data, (0,2,1))
            yield [input_data]
            #if input_data.shape >= torch.Size([1,160,24]):
            #    input_data = input_data[:, :192, :].cpu().numpy()
            #    print(input_data.shape)
            #    if input_data.shape != torch.Size([1,192,24]):
            #        padding = [(0, max(torch.Size([1,192,24])[i] - input_data.shape[i], 0)) for i in range(len(torch.Size([1,192,24])))]
            #        input_data = np.pad(input_data, padding, 'constant', constant_values=(0,))
            #    #np.save('/home/blakelu/8K_model/resnet_se_avgpool_D24/' + os.path.basename(cal_dataset.wav_paths[idx]) + '.npy', input_data.transpose(0, 2, 1))
            #    valid_cnt += 1
            #    if valid_cnt % 100 == 0:
            #        i = 0
            #        #print(f'valid_cnt: {valid_cnt}')
            #    #print(input_data)
            #    #input_data = np.transpose(input_data, (0, 2, 1))
            #    yield [input_data]
            #print(f'valid_cnt: {valid_cnt}')
    #representative_dataset = Dataloader()
            
    converter = tf.lite.TFLiteConverter.from_saved_model(pb_folder_path)

    converter.optimizations = [tf.lite.Optimize.DEFAULT]
    if mode == 1:
        converter.target_spec.supported_ops = [tf.lite.OpsSet.TFLITE_BUILTINS_INT8]
        converter.inference_input_type = tf.int8
        converter.inference_output_type = tf.int8
        converter.representative_dataset = representative_dataset
    elif mode == 2:
        converter.target_spec.supported_types = [tf.float16]
    elif mode == 3:
        tf_model = tf.saved_model.load(pb_folder_path)
        quant_aware_model = tfmot.quantization.keras.quantize_model(tf_model)
        quant_aware_model.compile(optimizer='adam',
                                    loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
                                    metrics=['accuracy'])
        quant_aware_model.fit(train_data, train_labels, batch_size=500, epochs=1, validation_split=0.1)
        converter = tf.lite.TFLiteConverter.from_saved_model(quant_aware_model)
        converter.optimizations = [tf.lite.Optimize.DEFAULT]

    tflite_model_content = converter.convert()
    tflite_quant_model = tf.lite.Interpreter(model_content=tflite_model_content)
    tflite_quant_model.allocate_tensors()
    print(tflite_quant_model.get_input_details())
    print(tflite_quant_model.get_output_details())

    #tflite_path = os.path.join(pb_folder_path,os.path.basename(pb_folder_path)) + '.tflite'
    tflite_path = sys.argv[3]
    with open(tflite_path, 'wb') as f:
        f.write(tflite_model_content)

def get_args():
    parser = argparse.ArgumentParser(description='export to onnx model')
    parser.add_argument('--pb_folder_path',
                        required=True)
    parser.add_argument('--mode',
                        required=True,
                        type=int)
    args = parser.parse_args()
    return args

if __name__ == '__main__':
    print('hello')
    pb_folder_path = sys.argv[1]
    data_path = sys.argv[2]
    mode = 1 
    convert_to_tflite_quant(pb_folder_path=pb_folder_path, data_path=data_path, mode=mode)
