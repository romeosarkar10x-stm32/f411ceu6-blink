#pragma once

#include <blink/types.hpp>
#include <blink/utilities/mask/count_trailing_zeros.hpp>
#include <blink/utilities/mask/get_bits.hpp>
#include <blink/utilities/mask/mask.hpp>
#include <blink/utilities/mask/set_bits.hpp>
#include <blink/utilities/mask/shift_left.hpp>
#include <blink/utilities/mask/shift_right.hpp>

#include "enums.hpp"

namespace reset_and_clock_control
{
    using utilities::get_bits;
    using utilities::set_bits;
    using utilities::u32_mask_v;

    namespace enum_mask
    {
        enum type : u32
        {
            TIM2_RESET = u32_mask_v<0>, // Bit 0: TIM2RST
            TIM3_RESET = u32_mask_v<1>, // Bit 1: TIM3RST
            TIM4_RESET = u32_mask_v<2>, // Bit 2: TIM4RST
            TIM5_RESET = u32_mask_v<3>, // Bit 3: TIM5RST
            // Bits 4:10 Reserved
            WINDOW_WATCHDOG_RESET = u32_mask_v<11>, // Bit 11: WWDGRST
            // Bits 12:13 Reserved
            SPI2_RESET = u32_mask_v<14>, // Bit 14: SPI2RST
            SPI3_RESET = u32_mask_v<15>, // Bit 15: SPI3RST
            // Bit 16 Reserved
            USART2_RESET = u32_mask_v<17>, // Bit 17: USART2RST
            // Bits 18:20 Reserved
            I2C1_RESET = u32_mask_v<21>, // Bit 21: I2C1RST
            I2C2_RESET = u32_mask_v<22>, // Bit 22: I2C2RST
            I2C3_RESET = u32_mask_v<23>, // Bit 23: I2C3RST
            // Bits 24:27 Reserved
            POWER_INTERFACE_RESET = u32_mask_v<28>, // Bit 28: PWRRST
            // Bits 29:31 Reserved
        };
    };

    struct apb1_peripheral_reset_register
    {
        constexpr apb1_peripheral_reset_register() {}

    private:
        u32 m_value = 0u;
    };

} // namespace reset_and_clock_control
