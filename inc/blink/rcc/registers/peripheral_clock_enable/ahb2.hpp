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
    namespace peripheral_clock_enable
    {
        using utilities::get_bits;
        using utilities::set_bits;
        using utilities::u32_mask_v;

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
    } // namespace peripheral_clock_enable
} // namespace rcc
