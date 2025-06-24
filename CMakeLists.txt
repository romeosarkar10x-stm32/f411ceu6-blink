cmake_minimum_required(VERSION 4.0)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/toolchain.cmake")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(blink VERSION 1.0.0 LANGUAGES CXX ASM)

set(CPU_PARAMETERS 
    "-mcpu=cortex-m4 \
    -mthumb \
    -mfpu=fpv4-sp-d16 \
    -mfloat-abi=hard"
)

set(CMAKE_CXX_FLAGS
    "${CPU_PARAMETERS} \
    -Wall \
    -ffunction-sections \
    -fdata-sections \
    -fstack-usage \
    -ffreestanding \
    -fno-exceptions \
    -fno-rtti \
    -fno-use-cxa-atexit \
    -fno-threadsafe-statics"
)

set(CMAKE_CXX_FLAGS_RELEASE "-O0")

# add_compile_definitions(
 #    USE_HAL_DRIVER
  #   STM32F411xE
# )

file(GLOB_RECURSE SOURCES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)
#     "${CMAKE_SOURCE_DIR}/drivers/stm32f4xx_hal/src/*.c"

# list(FILTER SOURCES EXCLUDE REGEX ".*template\\.c$")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

# TODO: add memory map generation using -Map=<filename.map>
set(CMAKE_EXE_LINKER_FLAGS
    "${CPU_PARAMETERS} \
    -static -nostartfiles \
    --specs=nano.specs --specs=nosys.specs \
    -Wl,--gc-sections -Wl,--print-memory-usage 
    -Wl,-T${CMAKE_SOURCE_DIR}/stm32f411ceu6_flash.ld"
)

set(TARGET_EXECUTABLE ${PROJECT_NAME}.elf)
set(TARGET_BINARY ${PROJECT_NAME}.bin)
set(TARGET_HEXDUMP ${PROJECT_NAME}.hex)

add_executable(${TARGET_EXECUTABLE} ${SOURCES})

target_include_directories(
    ${TARGET_EXECUTABLE}
    PUBLIC
    "${CMAKE_SOURCE_DIR}/inc"
)

#    "${CMAKE_SOURCE_DIR}/drivers/stm32f4xx_hal/inc"
#    "${CMAKE_SOURCE_DIR}/drivers/stm32f4xx_hal/cortex_microcontroller_software_interface_standard/Device/ST/STM32F4xx/Include/"
#    "${CMAKE_SOURCE_DIR}/drivers/stm32f4xx_hal/cortex_microcontroller_software_interface_standard/Include"

add_custom_command(TARGET ${TARGET_EXECUTABLE} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary ${TARGET_EXECUTABLE} ${TARGET_BINARY}
    COMMAND ${CMAKE_OBJDUMP} -xdts -EL -m armv7e-m ${TARGET_EXECUTABLE} > ${TARGET_HEXDUMP}
    COMMENT "Creating binary and hex files."
)