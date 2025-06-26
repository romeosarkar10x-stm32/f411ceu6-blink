#pragma once

#include <blink/types.hpp>
#include <blink/utility/mask/count_trailing_zeros.hpp>
#include <blink/utility/mask/get_bits.hpp>
#include <blink/utility/mask/mask.hpp>
#include <blink/utility/mask/set_bits.hpp>
#include <blink/utility/mask/shift_left.hpp>
#include <blink/utility/mask/shift_right.hpp>

#include "enums.hpp"

namespace reset_and_clock_control
{
    using utility::get_bits;
    using utility::set_bits;
    using utility::u32_mask_v;

    namespace enum_mask
    {
        enum type : u32
        {
            GPIOA_RESET = u32_mask_v<0>, // Bit 0: GPIOARST
            GPIOB_RESET = u32_mask_v<1>, // Bit 1: GPIOBRST
            GPIOC_RESET = u32_mask_v<2>, // Bit 2: GPIOCRST
            GPIOD_RESET = u32_mask_v<3>, // Bit 3: GPIODRST
            GPIOE_RESET = u32_mask_v<4>, // Bit 4: GPIOERST
            // Bits 5:6 Reserved
            GPIOH_RESET = u32_mask_v<7>, // Bit 7: GPIOHRST
            // Bits 8:11 Reserved
            CRC_RESET = u32_mask_v<12>, // Bit 12: CRCRST
            // Bits 13:20 Reserved
            DMA1_RESET = u32_mask_v<21>, // Bit 21: DMA1RST
            DMA2_RESET = u32_mask_v<22>, // Bit 22: DMA2RST
            // Bits 23:31 Reserved
        };
    };

    struct ahb1_peripheral_reset_register
    {
        constexpr ahb1_peripheral_reset_register() {}

    private:
        u32 m_value = 0u;
    };

} // namespace reset_and_clock_control
