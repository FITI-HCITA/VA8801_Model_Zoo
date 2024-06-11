import onnx
import os, sys
import torch
sys.path.append("../")
from network import SED
import json
import argparse
import onnxruntime as ort
import numpy as np
from tqdm import tqdm


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='export to onnx model')
    parser.add_argument('--onnx_model', '-o', required=True, help='output onnx model')
    parser.add_argument('--ckpt', type=str, required=True, help='checkpoint model')
    parser.add_argument('-n', '--n_mel', type=int, default=24, help='# of mel bins') 
    parser.add_argument('--version', '-v', type=int, default=12)
    args = parser.parse_args()

    model = SED(4, args.n_mel, pooling_type='TAP')
    
    pt = torch.load(args.ckpt, map_location='cpu')['model']
    model.load_state_dict(pt)
    model.eval()
    model.cpu()
    
    inp = torch.randn(1, 192, args.n_mel)

    torch.onnx.export(model, inp, args.onnx_model,
                      input_names=['input'],
                      output_names=['output'],
                      opset_version=args.version,
                      verbose=False,
                      )

    # Verify onnx precision
    torch_output = model(inp)
    print('run time session')
    ort_sess = ort.InferenceSession(args.onnx_model)
    onnx_output = ort_sess.run(None, {
        'input': inp.numpy(),
    })

    if torch.allclose(torch_output, torch.tensor(onnx_output[0]), atol=1e-5, rtol=1e-3):
        print('Export to onnx succeed!')
    else:
        print('''Export to onnx succeed, but pytorch/onnx have different
                 outputs when given the same input, please check!!!''')
