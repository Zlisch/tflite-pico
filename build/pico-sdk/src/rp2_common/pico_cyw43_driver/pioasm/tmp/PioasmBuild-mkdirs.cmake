# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/mac/2024S2/COMP2560/pico/pico-sdk/tools/pioasm"
  "/Users/mac/2024S2/COMP2560/pico-tflmicro/build/pioasm"
  "/Users/mac/2024S2/COMP2560/pico-tflmicro/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm"
  "/Users/mac/2024S2/COMP2560/pico-tflmicro/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/tmp"
  "/Users/mac/2024S2/COMP2560/pico-tflmicro/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp"
  "/Users/mac/2024S2/COMP2560/pico-tflmicro/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src"
  "/Users/mac/2024S2/COMP2560/pico-tflmicro/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/mac/2024S2/COMP2560/pico-tflmicro/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp/${subDir}")
endforeach()
