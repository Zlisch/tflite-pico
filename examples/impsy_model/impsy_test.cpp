#include "constants.h"
#include "xxs_impsy_model.h"
#include "hello_world_float_model_data.h"
#include "main_functions.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/micro_log.h"
#include "tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "tensorflow/lite/micro/system_setup.h"
#include "tensorflow/lite/schema/schema_generated.h"

// Globals, used for compatibility with Arduino-style sketches.
namespace {
const tflite::Model* model = nullptr;
tflite::MicroInterpreter* interpreter = nullptr;
TfLiteTensor* input = nullptr;
TfLiteTensor* output = nullptr;
int inference_count = 0;

constexpr int kTensorArenaSize = 80 * 1024;
uint8_t tensor_arena[kTensorArenaSize];
bool setupornot = false;
}  // namespace

// The name of this function is important for Arduino compatibility.
void setup() {
  printf("Setting up ...... \n");
  tflite::InitializeTarget();

  // // Map the model into a usable data structure. This doesn't involve any
  // // copying or parsing, it's a very lightweight operation.
  // model = tflite::GetModel(impsy_models_musicMDRNN_dim4_layers2_units32_mixtures5_scale10_tflite);
  // if (model->version() != TFLITE_SCHEMA_VERSION) {
  //   printf(
  //       "Model provided is schema version %d not equal "
  //       "to supported version %d.\n",
  //       model->version(), TFLITE_SCHEMA_VERSION);
  //   return;
  // }

  // // This pulls in all the operation implementations we need.
  // // NOLINTNEXTLINE(runtime-global-variables)
  // static tflite::MicroMutableOpResolver<1> resolver;
  // TfLiteStatus resolve_status = resolver.AddFullyConnected();
  // if (resolve_status != kTfLiteOk) {
  //   printf("Op resolution failed\n");
  //   return;
  // }

  // // Build an interpreter to run the model with.
  // static tflite::MicroInterpreter static_interpreter(
  //     model, resolver, tensor_arena, kTensorArenaSize);
  // interpreter = &static_interpreter;

  // // Allocate memory from the tensor_arena for the model's tensors.
  // TfLiteStatus allocate_status = interpreter->AllocateTensors();
  // if (allocate_status != kTfLiteOk) {
  //   printf("AllocateTensors() failed\n");
  //   return;
  // } else {
  //   printf("AllocateTensors() succeeded\n");
  // }

  // // Obtain pointers to the model's input and output tensors.
  // input = interpreter->input(0);
  // output = interpreter->output(0);

  // // Keep track of how many inferences we have performed.
  // inference_count = 0;

  // setupornot = true;
}

void loop() {
  if (!setupornot) {
    printf("Now setup ... \n");

    tflite::InitializeTarget();

    // Map the model into a usable data structure. This doesn't involve any
    // copying or parsing, it's a very lightweight operation.
    model = tflite::GetModel(models_musicMDRNN_dim4_layers2_units16_mixtures5_scale10_tflite);
    if (model->version() != TFLITE_SCHEMA_VERSION) {
      printf(
          "Model provided is schema version %d not equal "
          "to supported version %d.",
          model->version(), TFLITE_SCHEMA_VERSION);
      return;
    }

    // This pulls in all the operation implementations we need.
    // NOLINTNEXTLINE(runtime-global-variables)
    static tflite::MicroMutableOpResolver<1> resolver;
    TfLiteStatus resolve_status = resolver.AddFullyConnected();
    if (resolve_status != kTfLiteOk) {
      printf("Op resolution failed");
      return;
    }

    // Build an interpreter to run the model with.
    static tflite::MicroInterpreter static_interpreter(
        model, resolver, tensor_arena, kTensorArenaSize);
    interpreter = &static_interpreter;

    // Allocate memory from the tensor_arena for the model's tensors.
    TfLiteStatus allocate_status = interpreter->AllocateTensors(); // broken
    if (allocate_status != kTfLiteOk) {
      printf("AllocateTensors() failed");
      return;
    }
    


    setupornot = true;
  }

  // Calculate an x value to feed into the model. We compare the current
  // inference_count to the number of inferences per cycle to determine
  // our position within the range of possible x values the model was
  // trained on, and use this to calculate a value.
  float position = static_cast<float>(inference_count) /
                   static_cast<float>(kInferencesPerCycle);
  float x = position * kXrange;
  printf("x=%.6f\n", x); // working

  if (setupornot) {
    printf("Has been setup ... \n");
  } else {
    printf("setupornot still false! \n");
  }

  if (input == nullptr) {
    printf("input is null!\n");
  } else if (input->dims == nullptr) {
    printf("input->dims is null!\n");
  } else {
    printf("Size of input->dims->size: %d\n", input->dims->size);
  }

  if (interpreter == nullptr) {
    printf("interpreter is null!\n");
  } else {
    printf("interpreter is NOT null!\n");
  }

  // Quantize the input from floating-point to integer
  // int8_t x_quantized = x / input->params.scale + input->params.zero_point;
  // Place the quantized input in the model's input tensor
  // input->data.int8[0] = x_quantized;
  // input->data.f[0] = x;
  // for (int i = 0; i < 4; ++i) {
  //     input->data.f[i] = x;
  // }

  // Run inference, and report any error
  // TfLiteStatus invoke_status = interpreter->Invoke();
  // if (invoke_status != kTfLiteOk) {
  //   printf("Invoke failed on x: %f\n", static_cast<double>(x));
  //   return;
  // }

  // Obtain the quantized output from model's output tensor
  // int8_t y_quantized = output->data.int8[0];
  // Dequantize the output from integer to floating-point
  // float y = (y_quantized - output->params.zero_point) * output->params.scale;
  // float y = output->data.f[0];

  // printf("x=%.6f, data.f[0]=%.6f\n", x, y);

  // Increment the inference_counter, and reset it if we have reached
  // the total number per cycle
  // working
  inference_count += 1;
  if (inference_count >= kInferencesPerCycle) inference_count = 0;
}