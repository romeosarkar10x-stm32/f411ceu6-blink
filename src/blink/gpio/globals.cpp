#include <blink/gpio/globals.hpp>

namespace gpio
{
    gpio& gpio_a_global = *reinterpret_cast<gpio*>(GPIOA_BASE);
    gpio& gpio_b_global = *reinterpret_cast<gpio*>(GPIOB_BASE);
    gpio& gpio_c_global = *reinterpret_cast<gpio*>(GPIOC_BASE);
    gpio& gpio_d_global = *reinterpret_cast<gpio*>(GPIOD_BASE);
    gpio& gpio_e_global = *reinterpret_cast<gpio*>(GPIOE_BASE);
    gpio& gpio_h_global = *reinterpret_cast<gpio*>(GPIOH_BASE);
} // namespace gpio