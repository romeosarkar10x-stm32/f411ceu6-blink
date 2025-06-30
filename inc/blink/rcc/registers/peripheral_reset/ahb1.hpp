#pragma once

#include <blink/types.hpp>
#include <blink/utilities/mask/count_trailing_zeros.hpp>
#include <blink/utilities/mask/get_bits.hpp>
#include <blink/utilities/mask/mask.hpp>
#include <blink/utilities/mask/set_bits.hpp>
#include <blink/utilities/mask/shift_left.hpp>
#include <blink/utilities/mask/shift_right.hpp>

// #include "enums.hpp"

namespace rcc
{
    namespace peripheral_reset
    {
        using utilities::get_bits;
        using utilities::set_bits;
        using utilities::u32_mask_v;

        struct ahb1_peripheral_reset_register
        {
            enum enum_mask : u32
            {
                GPIO_A_RESET = u32_mask_v<0>,
                GPIO_B_RESET = u32_mask_v<1>,
                GPIO_C_RESET = u32_mask_v<2>,
                GPIO_D_RESET = u32_mask_v<3>,
                GPIO_E_RESET = u32_mask_v<4>,
                GPIO_H_RESET = u32_mask_v<7>,
                CRC_RESET    = u32_mask_v<12>,
                DMA1_RESET   = u32_mask_v<21>,
                DMA2_RESET   = u32_mask_v<22>,

            };
            constexpr ahb1_peripheral_reset_register() {}

        private:
            u32 m_value = 0u;
        };
    } // namespace peripheral_reset
} // namespace rcc
