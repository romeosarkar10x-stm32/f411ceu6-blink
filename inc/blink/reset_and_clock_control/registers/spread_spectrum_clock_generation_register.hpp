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
            MODULATION_PERIOD                 = u32_mask_v<0, 12>,
            INCREMENTATION_STEP               = u32_mask_v<13, 27>,
            SPREAD_SELECT                     = u32_mask_v<30>,
            SPREAD_SPECTRUM_MODULATION_ENABLE = u32_mask_v<31>,
        };
    };

    struct spread_spectrum_clock_generation_register
    {
        constexpr spread_spectrum_clock_generation_register() {}

    private:
        u32 m_value = 0u;
    };

} // namespace reset_and_clock_control