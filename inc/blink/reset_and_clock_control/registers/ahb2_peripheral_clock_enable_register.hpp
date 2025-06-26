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
            // Bits 0:6 Reserved
            USB_OTG_FS_CLOCK_ENABLE_DURING_SLEEP_MODE = u32_mask_v<7>, // Bit 7: OTGFSLPEN
                                                                       // Bits 8:31 Reserved
        };
    };

    struct ahb2_peripheral_clock_enable_register
    {
        constexpr ahb2_peripheral_clock_enable_register() {}

    private:
        u32 m_value = 0u;
    };

} // namespace reset_and_clock_control
