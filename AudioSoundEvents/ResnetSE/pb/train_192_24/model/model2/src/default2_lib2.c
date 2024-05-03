// tvm target: fiti 
#define TVM_EXPORTS
#include "tvm/runtime/c_runtime_api.h"
#include "tvm/runtime/c_backend_api.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <dlpack/dlpack.h>
#include <arm_nnfunctions.h>
#include <arm_nn_types.h>
#include <arm_nn_math_types.h>
#include "fiti_dla.h"
#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_0(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_2_var, uint8_t* global_workspace_3_var) {
  void* context_buffer_0_let = (&(global_workspace_3_var[55296]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {1,1};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {1, -128, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,24,192,1};
  cmsis_nn_dims filter_dims = {4,3,3,1};
  cmsis_nn_dims bias_dims = {1,1,1,4};
  cmsis_nn_dims output_dims = {1,24,192,4};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_1(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_4_var, uint8_t* global_workspace_5_var) {
  void* context_buffer_1_let = (&(global_workspace_5_var[55296]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -128, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,24,192,4};
  cmsis_nn_dims filter_dims = {4,1,1,4};
  cmsis_nn_dims bias_dims = {1,1,1,4};
  cmsis_nn_dims output_dims = {1,24,192,4};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_2(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_6_var, uint8_t* global_workspace_7_var) {
  void* context_buffer_2_let = (&(global_workspace_7_var[73728]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {1,1};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -128, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,24,192,4};
  cmsis_nn_dims filter_dims = {4,3,3,4};
  cmsis_nn_dims bias_dims = {1,1,1,4};
  cmsis_nn_dims output_dims = {1,24,192,4};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_3(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_8_var, uint8_t* global_workspace_9_var) {
  void* context_buffer_3_let = (&(global_workspace_9_var[73728]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -14, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,24,192,4};
  cmsis_nn_dims filter_dims = {8,1,1,4};
  cmsis_nn_dims bias_dims = {1,1,1,8};
  cmsis_nn_dims output_dims = {1,24,192,8};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_4(int8_t* input_0_, int8_t* input_1_, int8_t* output_, uint8_t* global_const_workspace_22_var, uint8_t* global_workspace_23_var) {
  //1 24 192 8 (36864)
  //1 1 1 8 (8)
  int n = 4608;
  int x = 8;
  int8_t* input_1_new = fiti_malloc(36864);
  for(int i=0;i<n;i++) {
    memcpy(input_1_new + i * x, input_1_, x);
  }

  fiti_mul_b(input_0_, input_1_new, 14, 1073741824, 1, 128, 1073741824, 1, output_, -1, 1160325917, -6, -128, 127, 36864);

  fiti_free(input_1_new);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_5(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_10_var, uint8_t* global_workspace_11_var) {
  void* context_buffer_4_let = (&(global_workspace_11_var[55296]));
  cmsis_nn_context context= {context_buffer_4_let,32};
  cmsis_nn_tile stride = {192,24};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_pool_params pool_params = {stride, padding, activation};
  cmsis_nn_dims input_dims = {1,24,192,8};
  cmsis_nn_dims filter_dims = {1,24,192,1};
  cmsis_nn_dims output_dims = {1,1,1,8};
  arm_cmsis_nn_status status = arm_avgpool_s8(&context, &pool_params, &input_dims, input_, &filter_dims, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_6(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_12_var, uint8_t* global_workspace_13_var) {
  fiti_slice_b(input_, output_, 0, 8, 1, 1, 8);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_7(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_14_var, uint8_t* global_workspace_15_var) {
  fiti_slice_b(input_, output_, 0, 8, 1, 1, 8);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_8(int8_t* input_, int8_t* filter_, int32_t* bias_, int8_t* output_, uint8_t* global_const_workspace_16_var, uint8_t* global_workspace_17_var) {
  fiti_dense_b(input_, filter_, bias_, 14, 0, 8, 1, 1545520158, 5, 0, 127, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_9(int8_t* input_, int8_t* filter_, int32_t* bias_, int8_t* output_, uint8_t* global_const_workspace_18_var, uint8_t* global_workspace_19_var) {
  fiti_dense_b(input_, filter_, bias_, 0, -10, 1, 8, 1147509385, -22, -128, 127, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_10(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_20_var, uint8_t* global_workspace_21_var) {
  fiti_sigmoid_b(input_, 8, 6.014737e-03f, 10, 3.906250e-03f, -128, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_12(int8_t* input_0_, int8_t* input_1_, int8_t* output_, uint8_t* global_const_workspace_26_var, uint8_t* global_workspace_27_var) {
  //1 24 192 8 (36864)
  //1 24 192 8 (36864)
  fiti_add_b(input_0_, input_1_, 1, 1101784763, 19, -7, 1073741824, 20, output_, -128, 1111854362, -17, -128, 127, 36864);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_13(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_24_var, uint8_t* global_workspace_25_var) {
  void* context_buffer_5_let = (&(global_workspace_25_var[110592]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, 7, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,24,192,4};
  cmsis_nn_dims filter_dims = {8,1,1,4};
  cmsis_nn_dims bias_dims = {1,1,1,8};
  cmsis_nn_dims output_dims = {1,24,192,8};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_15(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_28_var, uint8_t* global_workspace_29_var) {
  void* context_buffer_6_let = (&(global_workspace_29_var[73728]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -128, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,24,192,8};
  cmsis_nn_dims filter_dims = {4,1,1,8};
  cmsis_nn_dims bias_dims = {1,1,1,4};
  cmsis_nn_dims output_dims = {1,24,192,4};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_16(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_30_var, uint8_t* global_workspace_31_var) {
  void* context_buffer_7_let = (&(global_workspace_31_var[92160]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {1,1};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -128, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,24,192,4};
  cmsis_nn_dims filter_dims = {4,3,3,4};
  cmsis_nn_dims bias_dims = {1,1,1,4};
  cmsis_nn_dims output_dims = {1,24,192,4};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_17(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_32_var, uint8_t* global_workspace_33_var) {
  void* context_buffer_8_let = (&(global_workspace_33_var[92160]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, 9, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,24,192,4};
  cmsis_nn_dims filter_dims = {8,1,1,4};
  cmsis_nn_dims bias_dims = {1,1,1,8};
  cmsis_nn_dims output_dims = {1,24,192,8};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_18(int8_t* input_0_, int8_t* input_1_, int8_t* output_, uint8_t* global_const_workspace_46_var, uint8_t* global_workspace_47_var) {
  //1 24 192 8 (36864)
  //1 1 1 8 (8)
  int n = 4608;
  int x = 8;
  int8_t* input_1_new = fiti_malloc(36864);
  for(int i=0;i<n;i++) {
    memcpy(input_1_new + i * x, input_1_, x);
  }

  fiti_mul_b(input_0_, input_1_new, -9, 1073741824, 1, 128, 1073741824, 1, output_, 15, 1733230094, -7, -128, 127, 36864);

  fiti_free(input_1_new);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_19(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_34_var, uint8_t* global_workspace_35_var) {
  void* context_buffer_9_let = (&(global_workspace_35_var[73728]));
  cmsis_nn_context context= {context_buffer_9_let,32};
  cmsis_nn_tile stride = {192,24};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_pool_params pool_params = {stride, padding, activation};
  cmsis_nn_dims input_dims = {1,24,192,8};
  cmsis_nn_dims filter_dims = {1,24,192,1};
  cmsis_nn_dims output_dims = {1,1,1,8};
  arm_cmsis_nn_status status = arm_avgpool_s8(&context, &pool_params, &input_dims, input_, &filter_dims, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_20(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_36_var, uint8_t* global_workspace_37_var) {
  fiti_slice_b(input_, output_, 0, 8, 1, 1, 8);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_21(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_38_var, uint8_t* global_workspace_39_var) {
  fiti_slice_b(input_, output_, 0, 8, 1, 1, 8);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_22(int8_t* input_, int8_t* filter_, int32_t* bias_, int8_t* output_, uint8_t* global_const_workspace_40_var, uint8_t* global_workspace_41_var) {
  fiti_dense_b(input_, filter_, bias_, -9, 0, 8, 1, 1556085780, 15, 0, 127, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_23(int8_t* input_, int8_t* filter_, int32_t* bias_, int8_t* output_, uint8_t* global_const_workspace_42_var, uint8_t* global_workspace_43_var) {
  fiti_dense_b(input_, filter_, bias_, 0, -6, 1, 8, 1113993039, -22, -128, 127, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_24(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_44_var, uint8_t* global_workspace_45_var) {
  fiti_sigmoid_b(input_, 8, 5.366732e-03f, 6, 3.906250e-03f, -128, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_26(int8_t* input_0_, int8_t* input_1_, int8_t* output_, uint8_t* global_const_workspace_48_var, uint8_t* global_workspace_49_var) {
  //1 24 192 8 (36864)
  //1 24 192 8 (36864)
  fiti_add_b(input_0_, input_1_, -15, 1073741824, 20, 128, 1739287382, 19, output_, -128, 2105224233, -19, -128, 127, 36864);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_28(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_50_var, uint8_t* global_workspace_51_var) {
  void* context_buffer_10_let = (&(global_workspace_51_var[73728]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -128, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,24,192,8};
  cmsis_nn_dims filter_dims = {8,1,1,8};
  cmsis_nn_dims bias_dims = {1,1,1,8};
  cmsis_nn_dims output_dims = {1,24,192,8};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_29(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_52_var, uint8_t* global_workspace_53_var) {
  void* context_buffer_11_let = (&(global_workspace_53_var[82944]));
  cmsis_nn_tile stride = {2,2};
  cmsis_nn_tile padding = {1,1};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -128, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,24,192,8};
  cmsis_nn_dims filter_dims = {8,3,3,8};
  cmsis_nn_dims bias_dims = {1,1,1,8};
  cmsis_nn_dims output_dims = {1,12,96,8};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_30(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_54_var, uint8_t* global_workspace_55_var) {
  void* context_buffer_12_let = (&(global_workspace_55_var[82944]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -19, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,12,96,8};
  cmsis_nn_dims filter_dims = {16,1,1,8};
  cmsis_nn_dims bias_dims = {1,1,1,16};
  cmsis_nn_dims output_dims = {1,12,96,16};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_31(int8_t* input_0_, int8_t* input_1_, int8_t* output_, uint8_t* global_const_workspace_68_var, uint8_t* global_workspace_69_var) {
  //1 12 96 16 (18432)
  //1 1 1 16 (16)
  int n = 1152;
  int x = 16;
  int8_t* input_1_new = fiti_malloc(18432);
  for(int i=0;i<n;i++) {
    memcpy(input_1_new + i * x, input_1_, x);
  }

  fiti_mul_b(input_0_, input_1_new, 19, 1073741824, 1, 128, 1073741824, 1, output_, -16, 1947227202, -7, -128, 127, 18432);

  fiti_free(input_1_new);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_32(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_56_var, uint8_t* global_workspace_57_var) {
  void* context_buffer_13_let = (&(global_workspace_57_var[55296]));
  cmsis_nn_context context= {context_buffer_13_let,64};
  cmsis_nn_tile stride = {96,12};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_pool_params pool_params = {stride, padding, activation};
  cmsis_nn_dims input_dims = {1,12,96,16};
  cmsis_nn_dims filter_dims = {1,12,96,1};
  cmsis_nn_dims output_dims = {1,1,1,16};
  arm_cmsis_nn_status status = arm_avgpool_s8(&context, &pool_params, &input_dims, input_, &filter_dims, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_33(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_58_var, uint8_t* global_workspace_59_var) {
  fiti_slice_b(input_, output_, 0, 16, 1, 1, 16);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_34(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_60_var, uint8_t* global_workspace_61_var) {
  fiti_slice_b(input_, output_, 0, 16, 1, 1, 16);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_35(int8_t* input_, int8_t* filter_, int32_t* bias_, int8_t* output_, uint8_t* global_const_workspace_62_var, uint8_t* global_workspace_63_var) {
  fiti_dense_b(input_, filter_, bias_, 19, -128, 16, 2, 1190496408, -2, -128, 127, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_36(int8_t* input_, int8_t* filter_, int32_t* bias_, int8_t* output_, uint8_t* global_const_workspace_64_var, uint8_t* global_workspace_65_var) {
  fiti_dense_b(input_, filter_, bias_, 128, -19, 2, 16, 1489186921, -7, -128, 127, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_37(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_66_var, uint8_t* global_workspace_67_var) {
  fiti_sigmoid_b(input_, 16, 1.654948e-02f, 19, 3.906250e-03f, -128, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_39(int8_t* input_0_, int8_t* input_1_, int8_t* output_, uint8_t* global_const_workspace_72_var, uint8_t* global_workspace_73_var) {
  //1 12 96 16 (18432)
  //1 12 96 16 (18432)
  fiti_add_b(input_0_, input_1_, 16, 1801237510, 19, 4, 1073741824, 20, output_, -128, 1288176687, -18, -128, 127, 18432);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_40(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_70_var, uint8_t* global_workspace_71_var) {
  void* context_buffer_14_let = (&(global_workspace_71_var[73728]));
  cmsis_nn_tile stride = {2,2};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -4, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,24,192,8};
  cmsis_nn_dims filter_dims = {16,1,1,8};
  cmsis_nn_dims bias_dims = {1,1,1,16};
  cmsis_nn_dims output_dims = {1,12,96,16};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_42(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_74_var, uint8_t* global_workspace_75_var) {
  void* context_buffer_15_let = (&(global_workspace_75_var[36864]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -128, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,12,96,16};
  cmsis_nn_dims filter_dims = {8,1,1,16};
  cmsis_nn_dims bias_dims = {1,1,1,8};
  cmsis_nn_dims output_dims = {1,12,96,8};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_43(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_76_var, uint8_t* global_workspace_77_var) {
  void* context_buffer_16_let = (&(global_workspace_77_var[46080]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {1,1};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -128, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,12,96,8};
  cmsis_nn_dims filter_dims = {8,3,3,8};
  cmsis_nn_dims bias_dims = {1,1,1,8};
  cmsis_nn_dims output_dims = {1,12,96,8};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_44(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_78_var, uint8_t* global_workspace_79_var) {
  void* context_buffer_17_let = (&(global_workspace_79_var[46080]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, 15, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,12,96,8};
  cmsis_nn_dims filter_dims = {16,1,1,8};
  cmsis_nn_dims bias_dims = {1,1,1,16};
  cmsis_nn_dims output_dims = {1,12,96,16};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_45(int8_t* input_0_, int8_t* input_1_, int8_t* output_, uint8_t* global_const_workspace_92_var, uint8_t* global_workspace_93_var) {
  //1 12 96 16 (18432)
  //1 1 1 16 (16)
  int n = 1152;
  int x = 16;
  int8_t* input_1_new = fiti_malloc(18432);
  for(int i=0;i<n;i++) {
    memcpy(input_1_new + i * x, input_1_, x);
  }

  fiti_mul_b(input_0_, input_1_new, -15, 1073741824, 1, 128, 1073741824, 1, output_, 23, 1160957751, -6, -128, 127, 18432);

  fiti_free(input_1_new);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_46(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_80_var, uint8_t* global_workspace_81_var) {
  void* context_buffer_18_let = (&(global_workspace_81_var[36864]));
  cmsis_nn_context context= {context_buffer_18_let,64};
  cmsis_nn_tile stride = {96,12};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_pool_params pool_params = {stride, padding, activation};
  cmsis_nn_dims input_dims = {1,12,96,16};
  cmsis_nn_dims filter_dims = {1,12,96,1};
  cmsis_nn_dims output_dims = {1,1,1,16};
  arm_cmsis_nn_status status = arm_avgpool_s8(&context, &pool_params, &input_dims, input_, &filter_dims, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_47(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_82_var, uint8_t* global_workspace_83_var) {
  fiti_slice_b(input_, output_, 0, 16, 1, 1, 16);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_48(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_84_var, uint8_t* global_workspace_85_var) {
  fiti_slice_b(input_, output_, 0, 16, 1, 1, 16);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_49(int8_t* input_, int8_t* filter_, int32_t* bias_, int8_t* output_, uint8_t* global_const_workspace_86_var, uint8_t* global_workspace_87_var) {
  fiti_dense_b(input_, filter_, bias_, -15, -128, 16, 2, 1628080799, 0, -128, 127, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_50(int8_t* input_, int8_t* filter_, int32_t* bias_, int8_t* output_, uint8_t* global_const_workspace_88_var, uint8_t* global_workspace_89_var) {
  fiti_dense_b(input_, filter_, bias_, 128, -5, 2, 16, 1377647095, -9, -128, 127, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_51(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_90_var, uint8_t* global_workspace_91_var) {
  fiti_sigmoid_b(input_, 16, 6.070457e-03f, 5, 3.906250e-03f, -128, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_53(int8_t* input_0_, int8_t* input_1_, int8_t* output_, uint8_t* global_const_workspace_94_var, uint8_t* global_workspace_95_var) {
  //1 12 96 16 (18432)
  //1 12 96 16 (18432)
  fiti_add_b(input_0_, input_1_, -23, 1556836275, 19, 128, 1073741824, 20, output_, -128, 1245040129, -18, -128, 127, 18432);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_55(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_96_var, uint8_t* global_workspace_97_var) {
  void* context_buffer_19_let = (&(global_workspace_97_var[36864]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -128, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,12,96,16};
  cmsis_nn_dims filter_dims = {16,1,1,16};
  cmsis_nn_dims bias_dims = {1,1,1,16};
  cmsis_nn_dims output_dims = {1,12,96,16};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_56(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_98_var, uint8_t* global_workspace_99_var) {
  void* context_buffer_20_let = (&(global_workspace_99_var[41472]));
  cmsis_nn_tile stride = {2,2};
  cmsis_nn_tile padding = {1,1};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -128, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,12,96,16};
  cmsis_nn_dims filter_dims = {16,3,3,16};
  cmsis_nn_dims bias_dims = {1,1,1,16};
  cmsis_nn_dims output_dims = {1,6,48,16};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_57(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_100_var, uint8_t* global_workspace_101_var) {
  void* context_buffer_21_let = (&(global_workspace_101_var[41472]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, 1, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,6,48,16};
  cmsis_nn_dims filter_dims = {32,1,1,16};
  cmsis_nn_dims bias_dims = {1,1,1,32};
  cmsis_nn_dims output_dims = {1,6,48,32};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_58(int8_t* input_0_, int8_t* input_1_, int8_t* output_, uint8_t* global_const_workspace_114_var, uint8_t* global_workspace_115_var) {
  //1 6 48 32 (9216)
  //1 1 1 32 (32)
  int n = 288;
  int x = 32;
  int8_t* input_1_new = fiti_malloc(9216);
  for(int i=0;i<n;i++) {
    memcpy(input_1_new + i * x, input_1_, x);
  }

  fiti_mul_b(input_0_, input_1_new, -1, 1073741824, 1, 128, 1073741824, 1, output_, 3, 1940003329, -7, -128, 127, 9216);

  fiti_free(input_1_new);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_59(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_102_var, uint8_t* global_workspace_103_var) {
  void* context_buffer_22_let = (&(global_workspace_103_var[27648]));
  cmsis_nn_context context= {context_buffer_22_let,128};
  cmsis_nn_tile stride = {48,6};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_pool_params pool_params = {stride, padding, activation};
  cmsis_nn_dims input_dims = {1,6,48,32};
  cmsis_nn_dims filter_dims = {1,6,48,1};
  cmsis_nn_dims output_dims = {1,1,1,32};
  arm_cmsis_nn_status status = arm_avgpool_s8(&context, &pool_params, &input_dims, input_, &filter_dims, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_60(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_104_var, uint8_t* global_workspace_105_var) {
  fiti_slice_b(input_, output_, 0, 32, 1, 1, 32);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_61(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_106_var, uint8_t* global_workspace_107_var) {
  fiti_slice_b(input_, output_, 0, 32, 1, 1, 32);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_62(int8_t* input_, int8_t* filter_, int32_t* bias_, int8_t* output_, uint8_t* global_const_workspace_108_var, uint8_t* global_workspace_109_var) {
  fiti_dense_b(input_, filter_, bias_, -1, -128, 32, 4, 1322607656, -3, -128, 127, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_63(int8_t* input_, int8_t* filter_, int32_t* bias_, int8_t* output_, uint8_t* global_const_workspace_110_var, uint8_t* global_workspace_111_var) {
  fiti_dense_b(input_, filter_, bias_, 128, -9, 4, 32, 1327903885, -7, -128, 127, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_64(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_112_var, uint8_t* global_workspace_113_var) {
  fiti_sigmoid_b(input_, 32, 2.225693e-02f, 9, 3.906250e-03f, -128, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_66(int8_t* input_0_, int8_t* input_1_, int8_t* output_, uint8_t* global_const_workspace_118_var, uint8_t* global_workspace_119_var) {
  //1 6 48 32 (9216)
  //1 6 48 32 (9216)
  fiti_add_b(input_0_, input_1_, -3, 2010519898, 19, 3, 1073741824, 20, output_, -128, 1353859007, -18, -128, 127, 9216);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_67(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_116_var, uint8_t* global_workspace_117_var) {
  void* context_buffer_23_let = (&(global_workspace_117_var[36864]));
  cmsis_nn_tile stride = {2,2};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -3, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,12,96,16};
  cmsis_nn_dims filter_dims = {32,1,1,16};
  cmsis_nn_dims bias_dims = {1,1,1,32};
  cmsis_nn_dims output_dims = {1,6,48,32};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_69(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_120_var, uint8_t* global_workspace_121_var) {
  void* context_buffer_24_let = (&(global_workspace_121_var[18432]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -128, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,6,48,32};
  cmsis_nn_dims filter_dims = {16,1,1,32};
  cmsis_nn_dims bias_dims = {1,1,1,16};
  cmsis_nn_dims output_dims = {1,6,48,16};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_70(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_122_var, uint8_t* global_workspace_123_var) {
  void* context_buffer_25_let = (&(global_workspace_123_var[23040]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {1,1};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -128, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,6,48,16};
  cmsis_nn_dims filter_dims = {16,3,3,16};
  cmsis_nn_dims bias_dims = {1,1,1,16};
  cmsis_nn_dims output_dims = {1,6,48,16};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_71(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_124_var, uint8_t* global_workspace_125_var) {
  void* context_buffer_26_let = (&(global_workspace_125_var[23040]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, 1, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,6,48,16};
  cmsis_nn_dims filter_dims = {32,1,1,16};
  cmsis_nn_dims bias_dims = {1,1,1,32};
  cmsis_nn_dims output_dims = {1,6,48,32};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_72(int8_t* input_0_, int8_t* input_1_, int8_t* output_, uint8_t* global_const_workspace_138_var, uint8_t* global_workspace_139_var) {
  //1 6 48 32 (9216)
  //1 1 1 32 (32)
  int n = 288;
  int x = 32;
  int8_t* input_1_new = fiti_malloc(9216);
  for(int i=0;i<n;i++) {
    memcpy(input_1_new + i * x, input_1_, x);
  }

  fiti_mul_b(input_0_, input_1_new, -1, 1073741824, 1, 128, 1073741824, 1, output_, -4, 1312646765, -7, -128, 127, 9216);

  fiti_free(input_1_new);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_73(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_126_var, uint8_t* global_workspace_127_var) {
  void* context_buffer_27_let = (&(global_workspace_127_var[18432]));
  cmsis_nn_context context= {context_buffer_27_let,128};
  cmsis_nn_tile stride = {48,6};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_pool_params pool_params = {stride, padding, activation};
  cmsis_nn_dims input_dims = {1,6,48,32};
  cmsis_nn_dims filter_dims = {1,6,48,1};
  cmsis_nn_dims output_dims = {1,1,1,32};
  arm_cmsis_nn_status status = arm_avgpool_s8(&context, &pool_params, &input_dims, input_, &filter_dims, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_74(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_128_var, uint8_t* global_workspace_129_var) {
  fiti_slice_b(input_, output_, 0, 32, 1, 1, 32);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_75(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_130_var, uint8_t* global_workspace_131_var) {
  fiti_slice_b(input_, output_, 0, 32, 1, 1, 32);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_76(int8_t* input_, int8_t* filter_, int32_t* bias_, int8_t* output_, uint8_t* global_const_workspace_132_var, uint8_t* global_workspace_133_var) {
  fiti_dense_b(input_, filter_, bias_, -1, -128, 32, 4, 1185290471, -5, -128, 127, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_77(int8_t* input_, int8_t* filter_, int32_t* bias_, int8_t* output_, uint8_t* global_const_workspace_134_var, uint8_t* global_workspace_135_var) {
  fiti_dense_b(input_, filter_, bias_, 128, -15, 4, 32, 1103952332, -7, -128, 127, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_78(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_136_var, uint8_t* global_workspace_137_var) {
  fiti_sigmoid_b(input_, 32, 6.284436e-02f, 15, 3.906250e-03f, -128, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_80(int8_t* input_0_, int8_t* input_1_, int8_t* output_, uint8_t* global_const_workspace_140_var, uint8_t* global_workspace_141_var) {
  //1 6 48 32 (9216)
  //1 6 48 32 (9216)
  fiti_add_b(input_0_, input_1_, 4, 1073741824, 20, 128, 1952465043, 19, output_, -128, 1191315724, -18, -128, 127, 9216);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_82(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_142_var, uint8_t* global_workspace_143_var) {
  void* context_buffer_28_let = (&(global_workspace_143_var[13824]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -128, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,6,48,32};
  cmsis_nn_dims filter_dims = {16,1,1,32};
  cmsis_nn_dims bias_dims = {1,1,1,16};
  cmsis_nn_dims output_dims = {1,6,48,16};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_83(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_144_var, uint8_t* global_workspace_145_var) {
  void* context_buffer_29_let = (&(global_workspace_145_var[23040]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {1,1};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -128, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,6,48,16};
  cmsis_nn_dims filter_dims = {16,3,3,16};
  cmsis_nn_dims bias_dims = {1,1,1,16};
  cmsis_nn_dims output_dims = {1,6,48,16};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_84(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_146_var, uint8_t* global_workspace_147_var) {
  void* context_buffer_30_let = (&(global_workspace_147_var[23040]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -16, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,6,48,16};
  cmsis_nn_dims filter_dims = {32,1,1,16};
  cmsis_nn_dims bias_dims = {1,1,1,32};
  cmsis_nn_dims output_dims = {1,6,48,32};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_85(int8_t* input_0_, int8_t* input_1_, int8_t* output_, uint8_t* global_const_workspace_160_var, uint8_t* global_workspace_161_var) {
  //1 6 48 32 (9216)
  //1 1 1 32 (32)
  int n = 288;
  int x = 32;
  int8_t* input_1_new = fiti_malloc(9216);
  for(int i=0;i<n;i++) {
    memcpy(input_1_new + i * x, input_1_, x);
  }

  fiti_mul_b(input_0_, input_1_new, 16, 1073741824, 1, 128, 1073741824, 1, output_, -4, 2002886134, -7, -128, 127, 9216);

  fiti_free(input_1_new);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_86(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_148_var, uint8_t* global_workspace_149_var) {
  void* context_buffer_31_let = (&(global_workspace_149_var[18432]));
  cmsis_nn_context context= {context_buffer_31_let,128};
  cmsis_nn_tile stride = {48,6};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_pool_params pool_params = {stride, padding, activation};
  cmsis_nn_dims input_dims = {1,6,48,32};
  cmsis_nn_dims filter_dims = {1,6,48,1};
  cmsis_nn_dims output_dims = {1,1,1,32};
  arm_cmsis_nn_status status = arm_avgpool_s8(&context, &pool_params, &input_dims, input_, &filter_dims, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_87(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_150_var, uint8_t* global_workspace_151_var) {
  fiti_slice_b(input_, output_, 0, 32, 1, 1, 32);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_88(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_152_var, uint8_t* global_workspace_153_var) {
  fiti_slice_b(input_, output_, 0, 32, 1, 1, 32);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_89(int8_t* input_, int8_t* filter_, int32_t* bias_, int8_t* output_, uint8_t* global_const_workspace_154_var, uint8_t* global_workspace_155_var) {
  fiti_dense_b(input_, filter_, bias_, 16, -128, 32, 4, 1584610782, -4, -128, 127, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_90(int8_t* input_, int8_t* filter_, int32_t* bias_, int8_t* output_, uint8_t* global_const_workspace_156_var, uint8_t* global_workspace_157_var) {
  fiti_dense_b(input_, filter_, bias_, 128, -24, 4, 32, 1122957972, -7, -128, 127, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_91(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_158_var, uint8_t* global_workspace_159_var) {
  fiti_sigmoid_b(input_, 32, 2.495165e-02f, 24, 3.906250e-03f, -128, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_93(int8_t* input_0_, int8_t* input_1_, int8_t* output_, uint8_t* global_const_workspace_162_var, uint8_t* global_workspace_163_var) {
  //1 6 48 32 (9216)
  //1 6 48 32 (9216)
  fiti_add_b(input_0_, input_1_, 4, 1421499077, 19, 128, 1073741824, 20, output_, -128, 1078361036, -18, -128, 127, 9216);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_95(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_164_var, uint8_t* global_workspace_165_var) {
  void* context_buffer_32_let = (&(global_workspace_165_var[18432]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -128, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,6,48,32};
  cmsis_nn_dims filter_dims = {16,1,1,32};
  cmsis_nn_dims bias_dims = {1,1,1,16};
  cmsis_nn_dims output_dims = {1,6,48,16};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_96(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_166_var, uint8_t* global_workspace_167_var) {
  void* context_buffer_33_let = (&(global_workspace_167_var[23040]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {1,1};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -128, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,6,48,16};
  cmsis_nn_dims filter_dims = {16,3,3,16};
  cmsis_nn_dims bias_dims = {1,1,1,16};
  cmsis_nn_dims output_dims = {1,6,48,16};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_97(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_168_var, uint8_t* global_workspace_169_var) {
  void* context_buffer_34_let = (&(global_workspace_169_var[23040]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, 14, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,6,48,16};
  cmsis_nn_dims filter_dims = {32,1,1,16};
  cmsis_nn_dims bias_dims = {1,1,1,32};
  cmsis_nn_dims output_dims = {1,6,48,32};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_98(int8_t* input_0_, int8_t* input_1_, int8_t* output_, uint8_t* global_const_workspace_182_var, uint8_t* global_workspace_183_var) {
  //1 6 48 32 (9216)
  //1 1 1 32 (32)
  int n = 288;
  int x = 32;
  int8_t* input_1_new = fiti_malloc(9216);
  for(int i=0;i<n;i++) {
    memcpy(input_1_new + i * x, input_1_, x);
  }

  fiti_mul_b(input_0_, input_1_new, -14, 1073741824, 1, 128, 1073741824, 1, output_, 17, 1183978448, -7, -128, 127, 9216);

  fiti_free(input_1_new);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_99(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_170_var, uint8_t* global_workspace_171_var) {
  void* context_buffer_35_let = (&(global_workspace_171_var[18432]));
  cmsis_nn_context context= {context_buffer_35_let,128};
  cmsis_nn_tile stride = {48,6};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_pool_params pool_params = {stride, padding, activation};
  cmsis_nn_dims input_dims = {1,6,48,32};
  cmsis_nn_dims filter_dims = {1,6,48,1};
  cmsis_nn_dims output_dims = {1,1,1,32};
  arm_cmsis_nn_status status = arm_avgpool_s8(&context, &pool_params, &input_dims, input_, &filter_dims, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_100(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_172_var, uint8_t* global_workspace_173_var) {
  fiti_slice_b(input_, output_, 0, 32, 1, 1, 32);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_101(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_174_var, uint8_t* global_workspace_175_var) {
  fiti_slice_b(input_, output_, 0, 32, 1, 1, 32);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_102(int8_t* input_, int8_t* filter_, int32_t* bias_, int8_t* output_, uint8_t* global_const_workspace_176_var, uint8_t* global_workspace_177_var) {
  fiti_dense_b(input_, filter_, bias_, -14, -128, 32, 4, 1872081883, -5, -128, 127, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_103(int8_t* input_, int8_t* filter_, int32_t* bias_, int8_t* output_, uint8_t* global_const_workspace_178_var, uint8_t* global_workspace_179_var) {
  fiti_dense_b(input_, filter_, bias_, 128, 1, 4, 32, 1600608566, -8, -128, 127, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_104(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_180_var, uint8_t* global_workspace_181_var) {
  fiti_sigmoid_b(input_, 32, 8.159757e-02f, -1, 3.906250e-03f, -128, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_106(int8_t* input_0_, int8_t* input_1_, int8_t* output_, uint8_t* global_const_workspace_184_var, uint8_t* global_workspace_185_var) {
  //1 6 48 32 (9216)
  //1 6 48 32 (9216)
  fiti_add_b(input_0_, input_1_, -17, 1073741824, 20, 128, 1556181308, 19, output_, -128, 1481689090, -18, -128, 127, 9216);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_108(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_186_var, uint8_t* global_workspace_187_var) {
  void* context_buffer_36_let = (&(global_workspace_187_var[18432]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -128, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,6,48,32};
  cmsis_nn_dims filter_dims = {32,1,1,32};
  cmsis_nn_dims bias_dims = {1,1,1,32};
  cmsis_nn_dims output_dims = {1,6,48,32};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_109(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_188_var, uint8_t* global_workspace_189_var) {
  void* context_buffer_37_let = (&(global_workspace_189_var[20736]));
  cmsis_nn_tile stride = {2,2};
  cmsis_nn_tile padding = {1,1};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -128, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,6,48,32};
  cmsis_nn_dims filter_dims = {32,3,3,32};
  cmsis_nn_dims bias_dims = {1,1,1,32};
  cmsis_nn_dims output_dims = {1,3,24,32};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_110(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_190_var, uint8_t* global_workspace_191_var) {
  void* context_buffer_38_let = (&(global_workspace_191_var[20736]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -4, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,3,24,32};
  cmsis_nn_dims filter_dims = {64,1,1,32};
  cmsis_nn_dims bias_dims = {1,1,1,64};
  cmsis_nn_dims output_dims = {1,3,24,64};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_111(int8_t* input_0_, int8_t* input_1_, int8_t* output_, uint8_t* global_const_workspace_204_var, uint8_t* global_workspace_205_var) {
  //1 3 24 64 (4608)
  //1 1 1 64 (64)
  int n = 72;
  int x = 64;
  int8_t* input_1_new = fiti_malloc(4608);
  for(int i=0;i<n;i++) {
    memcpy(input_1_new + i * x, input_1_, x);
  }

  fiti_mul_b(input_0_, input_1_new, 4, 1073741824, 1, 128, 1073741824, 1, output_, -22, 1281276308, -7, -128, 127, 4608);

  fiti_free(input_1_new);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_112(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_192_var, uint8_t* global_workspace_193_var) {
  void* context_buffer_39_let = (&(global_workspace_193_var[13824]));
  cmsis_nn_context context= {context_buffer_39_let,256};
  cmsis_nn_tile stride = {24,3};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_pool_params pool_params = {stride, padding, activation};
  cmsis_nn_dims input_dims = {1,3,24,64};
  cmsis_nn_dims filter_dims = {1,3,24,1};
  cmsis_nn_dims output_dims = {1,1,1,64};
  arm_cmsis_nn_status status = arm_avgpool_s8(&context, &pool_params, &input_dims, input_, &filter_dims, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_113(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_194_var, uint8_t* global_workspace_195_var) {
  fiti_slice_b(input_, output_, 0, 64, 1, 1, 64);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_114(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_196_var, uint8_t* global_workspace_197_var) {
  fiti_slice_b(input_, output_, 0, 64, 1, 1, 64);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_115(int8_t* input_, int8_t* filter_, int32_t* bias_, int8_t* output_, uint8_t* global_const_workspace_198_var, uint8_t* global_workspace_199_var) {
  fiti_dense_b(input_, filter_, bias_, 4, -128, 64, 8, 2077013698, -6, -128, 127, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_116(int8_t* input_, int8_t* filter_, int32_t* bias_, int8_t* output_, uint8_t* global_const_workspace_200_var, uint8_t* global_workspace_201_var) {
  fiti_dense_b(input_, filter_, bias_, 128, 4, 8, 64, 1718502999, -7, -128, 127, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_117(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_202_var, uint8_t* global_workspace_203_var) {
  fiti_sigmoid_b(input_, 64, 5.945432e-02f, -4, 3.906250e-03f, -128, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_119(int8_t* input_0_, int8_t* input_1_, int8_t* output_, uint8_t* global_const_workspace_208_var, uint8_t* global_workspace_209_var) {
  //1 3 24 64 (4608)
  //1 3 24 64 (4608)
  fiti_add_b(input_0_, input_1_, 22, 1073741824, 20, 7, 1945128482, 19, output_, -128, 2146858926, -18, -128, 127, 4608);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_120(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_206_var, uint8_t* global_workspace_207_var) {
  void* context_buffer_40_let = (&(global_workspace_207_var[18432]));
  cmsis_nn_tile stride = {2,2};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -7, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,6,48,32};
  cmsis_nn_dims filter_dims = {64,1,1,32};
  cmsis_nn_dims bias_dims = {1,1,1,64};
  cmsis_nn_dims output_dims = {1,3,24,64};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_122(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_210_var, uint8_t* global_workspace_211_var) {
  void* context_buffer_41_let = (&(global_workspace_211_var[6912]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -128, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,3,24,64};
  cmsis_nn_dims filter_dims = {32,1,1,64};
  cmsis_nn_dims bias_dims = {1,1,1,32};
  cmsis_nn_dims output_dims = {1,3,24,32};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_123(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_212_var, uint8_t* global_workspace_213_var) {
  void* context_buffer_42_let = (&(global_workspace_213_var[11520]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {1,1};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, -128, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,3,24,32};
  cmsis_nn_dims filter_dims = {32,3,3,32};
  cmsis_nn_dims bias_dims = {1,1,1,32};
  cmsis_nn_dims output_dims = {1,3,24,32};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_124(int8_t* input_, int8_t* filter_, int32_t* multiplier_, int32_t* bias_, int32_t* shift_, int8_t* output_, uint8_t* global_const_workspace_214_var, uint8_t* global_workspace_215_var) {
  void* context_buffer_43_let = (&(global_workspace_215_var[11520]));
  cmsis_nn_tile stride = {1,1};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_tile dilation = {1,1};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_conv_params conv_params = {128, 27, stride, padding, dilation, activation};
  cmsis_nn_per_channel_quant_params quant_params = {multiplier_, shift_};
  cmsis_nn_dims input_dims = {1,3,24,32};
  cmsis_nn_dims filter_dims = {64,1,1,32};
  cmsis_nn_dims bias_dims = {1,1,1,64};
  cmsis_nn_dims output_dims = {1,3,24,64};
  fiti_convolve_wrapper_s8_b(&conv_params, &quant_params, &input_dims, input_, &filter_dims, filter_, &bias_dims, bias_, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_125(int8_t* input_0_, int8_t* input_1_, int8_t* output_, uint8_t* global_const_workspace_228_var, uint8_t* global_workspace_229_var) {
  //1 3 24 64 (4608)
  //1 1 1 64 (64)
  int n = 72;
  int x = 64;
  int8_t* input_1_new = fiti_malloc(4608);
  for(int i=0;i<n;i++) {
    memcpy(input_1_new + i * x, input_1_, x);
  }

  fiti_mul_b(input_0_, input_1_new, -27, 1073741824, 1, 128, 1073741824, 1, output_, 17, 1483815498, -7, -128, 127, 4608);

  fiti_free(input_1_new);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_126(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_216_var, uint8_t* global_workspace_217_var) {
  void* context_buffer_44_let = (&(global_workspace_217_var[9216]));
  cmsis_nn_context context= {context_buffer_44_let,256};
  cmsis_nn_tile stride = {24,3};
  cmsis_nn_tile padding = {0,0};
  cmsis_nn_activation activation = {-128,127};
  cmsis_nn_pool_params pool_params = {stride, padding, activation};
  cmsis_nn_dims input_dims = {1,3,24,64};
  cmsis_nn_dims filter_dims = {1,3,24,1};
  cmsis_nn_dims output_dims = {1,1,1,64};
  arm_cmsis_nn_status status = arm_avgpool_s8(&context, &pool_params, &input_dims, input_, &filter_dims, &output_dims, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_127(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_218_var, uint8_t* global_workspace_219_var) {
  fiti_slice_b(input_, output_, 0, 64, 1, 1, 64);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_128(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_220_var, uint8_t* global_workspace_221_var) {
  fiti_slice_b(input_, output_, 0, 64, 1, 1, 64);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_129(int8_t* input_, int8_t* filter_, int32_t* bias_, int8_t* output_, uint8_t* global_const_workspace_222_var, uint8_t* global_workspace_223_var) {
  fiti_dense_b(input_, filter_, bias_, -27, -128, 64, 8, 1801864524, -5, -128, 127, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_130(int8_t* input_, int8_t* filter_, int32_t* bias_, int8_t* output_, uint8_t* global_const_workspace_224_var, uint8_t* global_workspace_225_var) {
  fiti_dense_b(input_, filter_, bias_, 128, -14, 8, 64, 1503460021, -7, -128, 127, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_131(int8_t* input_, int8_t* output_, uint8_t* global_const_workspace_226_var, uint8_t* global_workspace_227_var) {
  fiti_sigmoid_b(input_, 64, 4.308352e-02f, 14, 3.906250e-03f, -128, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_133(int8_t* input_0_, int8_t* input_1_, int8_t* output_, uint8_t* global_const_workspace_230_var, uint8_t* global_workspace_231_var) {
  //1 3 24 64 (4608)
  //1 3 24 64 (4608)
  fiti_add_b(input_0_, input_1_, -17, 1073741824, 20, 128, 1538490706, 19, output_, -128, 1285804754, -18, -128, 127, 4608);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_135(int8_t* input_0_, int8_t* input_1_, int8_t* output_, uint8_t* global_const_workspace_238_var, uint8_t* global_workspace_239_var) {
  //1 192 (192)
  //192 (192)
  fiti_mul_b(input_0_, input_1_, 128, 1073741824, 1, 128, 1073741824, 1, output_, -128, 1546295187, -5, -128, 127, 192);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_137(int8_t* input_0_, int8_t* input_1_, int8_t* output_, uint8_t* global_const_workspace_240_var, uint8_t* global_workspace_241_var) {
  //1 192 (192)
  //192 (192)
  fiti_add_b(input_0_, input_1_, 128, 1073741824, 20, -127, 1532782278, 16, output_, -107, 2012622313, -19, -128, 127, 192);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_139(int8_t* input_, int8_t* filter_, int8_t* output_, uint8_t* global_const_workspace_242_var, uint8_t* global_workspace_243_var) {
  fiti_dense_b(input_, filter_, NULL, 107, -6, 192, 64, 1309273836, -8, -128, 127, output_);
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default2_fiti_main_140(int8_t* input_, int8_t* filter_, int32_t* bias_, int8_t* output_, uint8_t* global_const_workspace_244_var, uint8_t* global_workspace_245_var) {
  fiti_dense_b(input_, filter_, bias_, 6, 39, 64, 4, 1507141198, -10, -128, 127, output_);
  return 0;
}

