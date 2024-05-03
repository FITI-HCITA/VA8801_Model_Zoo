#ifndef TVMGEN_DEFAULT2_H_
#define TVMGEN_DEFAULT2_H_
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Input tensor serving_default_input_0 size (in bytes) for TVM module "default2" 
 */
#define TVMGEN_DEFAULT2_SERVING_DEFAULT_INPUT_0_SIZE 4608
/*!
 * \brief Output tensor PartitionedCall_0 size (in bytes) for TVM module "default2" 
 */
#define TVMGEN_DEFAULT2_PARTITIONEDCALL_0_SIZE 4
/*!
 * \brief Input tensor pointers for TVM module "default2" 
 */
struct tvmgen_default2_inputs {
  void* serving_default_input_0;
};

/*!
 * \brief Output tensor pointers for TVM module "default2" 
 */
struct tvmgen_default2_outputs {
  void* PartitionedCall_0;
};

/*!
 * \brief entrypoint function for TVM module "default2"
 * \param inputs Input tensors for the module 
 * \param outputs Output tensors for the module 
 */
int32_t tvmgen_default2_run(
  struct tvmgen_default2_inputs* inputs,
  struct tvmgen_default2_outputs* outputs
);
/*!
 * \brief Workspace size for TVM module "default2" 
 */
#define TVMGEN_DEFAULT2_WORKSPACE_SIZE 110600

#ifdef __cplusplus
}
#endif

#endif // TVMGEN_DEFAULT2_H_
