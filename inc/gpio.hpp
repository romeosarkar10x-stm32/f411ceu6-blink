
#include <cstdint>

#include "memory_map.hpp"

namespace gpio
{
    enum enum_gpio_mode
    {
        GPIO_MODE_INPUT,
        GPIO_MODE_GENERAL_PURPOSE_OUTPUT,
        GPIO_MODE_ALTERNATE_FUNCTION,
        GPIO_MODE_ANALOG
    };

    struct GPIO_Registers
    {
        uint32_t mode;
        uint32_t output_type;
        uint32_t output_speed;
        uint32_t pull_up_pull_down;
        uint32_t input_data;
        uint32_t output_data;
        uint32_t bit_set_reset;
        uint32_t lock;

        struct alternate_function_registers
        {
            uint32_t low;
            uint32_t high;
        } alternate_function;
    };

} // namespace gpio