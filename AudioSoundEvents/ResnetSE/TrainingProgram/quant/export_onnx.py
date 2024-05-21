import onnx
import os, sys
sys.path.append("../")
import torch
from network import KWS
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
    parser.add_argument('--inp', type=str, required=True, help='inp data of onnx model')
    parser.add_argument('--out', type=str, required=True, help='inp data of onnx model')
    parser.add_argument('--version', '-v', type=int, default=10)
    args = parser.parse_args()

    model = KWS(4, args.n_mel, pooling_type='TAP')
    
    pt = torch.load(args.ckpt, map_location='cpu')['model']
    model.load_state_dict(pt)
    model.eval()
    model.cpu()
    
    inp = torch.randn(1, 192, args.n_mel)

    torch.onnx.export(model, inp, args.onnx_model,
                      input_names=['input'],
                      output_names=['output'],
                      opset_version=args.version,
                      #dynamic_axes = { 
                      #    'input': {0:'batch_size'},
                      #    'output': {0:'batch_size'}, 
                      #    },
                      verbose=False,
                      )

    # Verify onnx precision
    torch_output = model(inp)
    print('run time session')
    ort_sess = ort.InferenceSession(args.onnx_model)
    onnx_output = ort_sess.run(None, {
        'input': inp.numpy(),
    })

    #if torch.allclose(torch_output, torch.tensor(onnx_output[0]), atol=1e-6):
    if torch.allclose(torch_output, torch.tensor(onnx_output[0]), atol=1e-5, rtol=1e-3):
        print('Export to onnx succeed!')
    else:
        print('''Export to onnx succeed, but pytorch/onnx have different
                 outputs when given the same input, please check!!!''')
    
    #
    inps = np.load(args.inp)
    #th_inps = torch.from_numpy(inps).float()
    #th_outs = model(th_inps).detach()
    inps = np.expand_dims(inps, 1)
    onnx_outs = []
    th_outs = []
    print("verify on real data")
    for i in tqdm(range(len(inps))):
        inp = inps[i]
        out = ort_sess.run(None, {'input': inp})
        onnx_outs.append(out[0])
        #
        y = model(torch.from_numpy(inp).float()).detach()
        th_outs.append(y)
    th_outs = torch.cat(th_outs)
    onnx_outs = np.array(onnx_outs).squeeze()
    print('torch out: ', th_outs.size())
    print('onnx out: ', onnx_outs.shape)
    if torch.allclose(th_outs, torch.tensor(onnx_outs), atol=1e-5, rtol=1e-3):
        print('Succeed')
    else:
        print('fail')
    np.save(args.out, onnx_outs)
    print(onnx_outs.shape)
    idx = np.random.randint(0, len(th_outs))
    print(onnx_outs[idx])
    print(th_outs[idx])
    print( np.abs( th_outs.numpy() - onnx_outs).max())
