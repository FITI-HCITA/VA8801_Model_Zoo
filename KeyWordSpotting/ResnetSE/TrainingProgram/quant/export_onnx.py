import onnx
import os, sys
sys.path.append("../")
import torch
from network import KWS
import json
import argparse
import onnxruntime as ort


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='export to onnx model')
    parser.add_argument('--onnx_model', '-o', 
                        required=True,
                        help='output onnx model')
    parser.add_argument('--ckpt', type=str, required=True, help='checkpoint model')
    parser.add_argument('-n', '--n_mel', type=int, default=24, help='# of mel bins') 
    args = parser.parse_args()

    model = KWS(3, args.n_mel, pooling_type='TAP')
    
    pt = torch.load(args.ckpt, map_location='cpu')['model']
    model.load_state_dict(pt)
    model.eval()
    model.cpu()
    
    inp = torch.randn(1, 192, args.n_mel)
    dummy_input = inp

    torch.onnx.export(model, inp, args.onnx_model,
                      input_names=['input'],
                      output_names=['output'],
                      opset_version=12,
                      verbose=False,
                      )
    # Add hidden dim and cache size
    onnx_model = onnx.load(args.onnx_model)

    # Verify onnx precision
    torch_output = model(dummy_input)
    print('run time session')
    ort_sess = ort.InferenceSession(args.onnx_model)
    onnx_output = ort_sess.run(None, {
        'input': dummy_input.numpy(),
    })

    if torch.allclose(torch_output,
            torch.tensor(onnx_output), atol=1e-6):
        print('Export to onnx succeed!')
    else:
        print('''Export to onnx succeed, but pytorch/onnx have different
                 outputs when given the same input, please check!!!''')