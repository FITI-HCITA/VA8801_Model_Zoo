import onnx
import os, sys
sys.path.append("/4T/john/kws/sed_kws_fbank")
import torch
from network import KWS
import json
import argparse
import onnxruntime as ort


class FOO():
    def __init__(self, config):
        self.hidden_dim = config['hidden_dim']
        self.input_dim = config['input_dim']
        self.output_dim = config['output_dim']

        self.num_layers = config['num_layers']
        self.kernel_size = config['kernel_size']
        self.dropout = config['dropout']
        self.tcn_dropout = 0.0
        self.classifier_type = config['classifier_type']
        self.criterion = config['criterion']


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='export to onnx model')
    #parser.add_argument('--config', type=str, required=True, help='config file')
    parser.add_argument('--onnx_model', '-o', 
                        required=True,
                        help='output onnx model')
    parser.add_argument('--ckpt', type=str, required=True, help='checkpoint model')
    parser.add_argument('-n', '--n_mel', type=int, default=24, help='# of mel bins') 
    args = parser.parse_args()

    model = KWS(16, args.n_mel, pooling_type='TAP')
    
    pt = torch.load(args.ckpt, map_location='cpu')['model']
    model.load_state_dict(pt)
    model.eval()
    model.cpu()
    
    #inp = torch.randn(1, 160, 24)
    inp = torch.randn(1, 192, args.n_mel)
    dummy_input = inp

    torch.onnx.export(model, inp, args.onnx_model,
                      input_names=['input'],
                      output_names=['output'],
                      #dynamic_axes={
                      #    'input': {1:'T'},
                      #    },
                      opset_version=12,
                      verbose=False,
                      )
    # Add hidden dim and cache size
    onnx_model = onnx.load(args.onnx_model)
    #meta = onnx_model.metadata_props.add()
    #meta.key, meta.value = 'cache_dim', str(model.hdim)
    #meta = onnx_model.metadata_props.add()
    #meta.key, meta.value = 'cache_len', str(model.backbone.padding)
    #onnx.save(onnx_model, args.onnx_model)

    # Verify onnx precision
    torch_output = model(dummy_input)
    print('run time session')
    ort_sess = ort.InferenceSession(args.onnx_model)
    onnx_output = ort_sess.run(None, {
        'input': dummy_input.numpy(),
    })

    #if torch.allclose(torch_output,
    #        torch.tensor(onnx_output), atol=1e-6):
    #    print('Export to onnx succeed!')
    #else:
    #    print('''Export to onnx succeed, but pytorch/onnx have different
    #             outputs when given the same input, please check!!!''')
