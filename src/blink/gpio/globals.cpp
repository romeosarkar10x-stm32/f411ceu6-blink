#include <blink/gpio/globals.hpp>

namespace gpio
{
    gpio& gpio_a = *reinterpret_cast<gpio*>(GPIOA_BASE);
    gpio& gpio_b = *reinterpret_cast<gpio*>(GPIOB_BASE);
    gpio& gpio_c = *reinterpret_cast<gpio*>(GPIOC_BASE);
    gpio& gpio_d = *reinterpret_cast<gpio*>(GPIOD_BASE);
    gpio& gpio_e = *reinterpret_cast<gpio*>(GPIOE_BASE);
    gpio& gpio_h = *reinterpret_cast<gpio*>(GPIOH_BASE);
} // namespace gpio