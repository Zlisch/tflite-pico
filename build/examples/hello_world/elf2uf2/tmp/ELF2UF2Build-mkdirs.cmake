# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/mac/2024S2/COMP2560/pico/pico-sdk/tools/elf2uf2"
  "/Users/mac/2024S2/COMP2560/pico-tflmicro/build/elf2uf2"
  "/Users/mac/2024S2/COMP2560/pico-tflmicro/build/examples/hello_world/elf2uf2"
  "/Users/mac/2024S2/COMP2560/pico-tflmicro/build/examples/hello_world/elf2uf2/tmp"
  "/Users/mac/2024S2/COMP2560/pico-tflmicro/build/examples/hello_world/elf2uf2/src/ELF2UF2Build-stamp"
  "/Users/mac/2024S2/COMP2560/pico-tflmicro/build/examples/hello_world/elf2uf2/src"
  "/Users/mac/2024S2/COMP2560/pico-tflmicro/build/examples/hello_world/elf2uf2/src/ELF2UF2Build-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/mac/2024S2/COMP2560/pico-tflmicro/build/examples/hello_world/elf2uf2/src/ELF2UF2Build-stamp/${subDir}")
endforeach()
