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
            DIVISION_FACTOR_FOR_AUDIO_PLL_INPUT_CLOCK =
                u32_mask_v<0, 5>, // Bits 5:0 - Division factor for the audio PLL (PLLI2S) input clock
            MULTIPLICATION_FACTOR_FOR_VCO = u32_mask_v<6, 14>, // Bits 14:6 - PLLI2S multiplication factor for VCO
            // Bits 15:27 Reserved
            DIVISION_FACTOR_FOR_I2S_CLOCKS = u32_mask_v<28, 30>, // Bits 30:28 - PLLI2S division factor for I2S clocks
            // Bit 31 Reserved
        };
    };

    struct pll_i2s_configuration_register
    {
        constexpr pll_i2s_configuration_register() {}

    private:
        u32 m_value = 0u;
    };

} // namespace reset_and_clock_control
