
cmake_minimum_required(VERSION 3.12)

project(impsy_model C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)


# add_executable(impsy_test "")

# target_include_directories(impsy_test
#   PRIVATE
#   ${CMAKE_CURRENT_LIST_DIR}/.
# )

# set_target_properties(
#   impsy_test
#   PROPERTIES
#   COMPILE_FLAGS -fno-rtti
#   COMPILE_FLAGS -fno-exceptions
#   COMPILE_FLAGS -fno-threadsafe-statics
#   COMPILE_FLAGS -nostdlib
# )

# target_sources(impsy_test
#   PRIVATE
#   ${CMAKE_CURRENT_LIST_DIR}/musicMDRNN-dim4-layers2-units32-mixtures5-scale10.cc
#   ${CMAKE_CURRENT_LIST_DIR}/impsy_test.cpp
# )

# target_link_libraries(
#   impsy_test
#   pico-tflmicro
#   hardware_pwm
#   pico-tflmicro_test
#   pico_cyw43_arch_none
# )

# pico_enable_stdio_usb(impsy_test 1)
# pico_enable_stdio_uart(impsy_test 0)

# pico_add_extra_outputs(impsy_test)

add_executable(impsy_test "")

target_include_directories(impsy_test
  PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/.
)

set_target_properties(
  impsy_test
  PROPERTIES
  COMPILE_FLAGS -fno-rtti
  COMPILE_FLAGS -fno-exceptions
  COMPILE_FLAGS -fno-threadsafe-statics
  COMPILE_FLAGS -nostdlib
)

target_sources(impsy_test
  PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/constants.cpp
  ${CMAKE_CURRENT_LIST_DIR}/musicMDRNN-dim4-layers2-units32-mixtures5-scale10.cc
  ${CMAKE_CURRENT_LIST_DIR}/hello_world_float_model_data.cpp
  ${CMAKE_CURRENT_LIST_DIR}/xxs_impsy_model.cc
  ${CMAKE_CURRENT_LIST_DIR}/main.cpp
  ${CMAKE_CURRENT_LIST_DIR}/impsy_test.cpp
  ${CMAKE_CURRENT_LIST_DIR}/constants.h
  ${CMAKE_CURRENT_LIST_DIR}/main_functions.h
)

target_link_libraries(
  impsy_test
  pico-tflmicro
  hardware_pwm
  # pico_cyw43_arch_none
)

pico_enable_stdio_usb(impsy_test 1)
pico_enable_stdio_uart(impsy_test 0)

pico_add_extra_outputs(impsy_test)
