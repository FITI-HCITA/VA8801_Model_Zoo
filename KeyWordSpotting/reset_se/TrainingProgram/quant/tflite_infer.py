import onnx
import onnxruntime as ort
import onnx
import tensorflow as tf
from pathlib import Path
from tqdm import tqdm
import numpy as np
import os, sys
import tensorflow as tf
import tensorflow_model_optimization as tfmot

def verify_tflite(inps, ground_outs, tflite_path):
    intrp = tf.lite.Interpreter(model_path=tflite_path)
    intrp.allocate_tensors()
    in_info = intrp.get_input_details()
    out_info = intrp.get_output_details()
    
    in_idx = in_info[0]['index']
    in_quant_scale = in_info[0]['quantization_parameters']['scales'][0]
    in_quant_zero_point = in_info[0]['quantization_parameters']['zero_points'][0]

    out_idx = out_info[0]['index']
    out_quant_scale = out_info[0]['quantization_parameters']['scales'][0]
    out_quant_zero_point = out_info[0]['quantization_parameters']['zero_points'][0]
    '''
    x = scale * (x_q - zero)
    x_q = x/scale + zero
    '''
    inps_q = inps/in_quant_scale + in_quant_zero_point
    inps_q = np.round(inps_q).astype(np.int8)
    outs_q = []
    print('run tflite model...')
    for i in tqdm(range(len(inps_q))):
        inp = np.expand_dims(inps_q[i], 0)
        intrp.set_tensor(in_idx, inp)
        intrp.invoke()
        out = intrp.get_tensor(out_idx)
        outs_q.append(out)
    outs_q = np.array(outs_q).squeeze()
    outs = (outs_q.astype(np.float32) - out_quant_zero_point) * out_quant_scale
    p = np.exp(outs) / np.sum( np.exp(outs), axis=-1, keepdims=True)
    tp = np.exp(ground_outs) / np.sum( np.exp(ground_outs), axis=-1, keepdims=True)
    print(p[:4])

if __name__ == "__main__":
    # inference tflite
    #print(onnx_outs.shape)
    if len(sys.argv) < 4:
        print(f"Usage: {__file__} [inp fts] [out fts] [tflite model]")
        sys.exit(1)
    fts = np.load(sys.argv[1])
    fts = fts.transpose(0,2,1)
    onnx_outs = np.load(sys.argv[2])
    tflite_path = sys.argv[3]
    verify_tflite(fts, onnx_outs, tflite_path)
