#pragma once

#include <blink/types.hpp>
#include <blink/utilities/mask/count_trailing_zeros.hpp>
#include <blink/utilities/mask/get_bits.hpp>
#include <blink/utilities/mask/mask.hpp>
#include <blink/utilities/mask/set_bits.hpp>
#include <blink/utilities/mask/shift_left.hpp>
#include <blink/utilities/mask/shift_right.hpp>

namespace rcc
{
    namespace clock
    {
        using utilities::get_bits;
        using utilities::set_bits;
        using utilities::u32_mask_v;

        struct spread_spectrum_clock_generation_register
        {
            enum enum_mask : u32
            {
                MODULATION_PERIOD                 = u32_mask_v<0, 12>,
                INCREMENTATION_STEP               = u32_mask_v<13, 27>,
                SPREAD_SELECT                     = u32_mask_v<30>,
                SPREAD_SPECTRUM_MODULATION_ENABLE = u32_mask_v<31>,
            };

            constexpr spread_spectrum_clock_generation_register() {}

        private:
            u32 m_value = 0u;
        };
    } // namespace clock
} // namespace rcc