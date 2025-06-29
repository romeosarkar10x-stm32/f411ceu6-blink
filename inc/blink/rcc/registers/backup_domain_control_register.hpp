#pragma once

#include <blink/types.hpp>
#include <blink/utilities/mask/count_trailing_zeros.hpp>
#include <blink/utilities/mask/get_bits.hpp>
#include <blink/utilities/mask/mask.hpp>
#include <blink/utilities/mask/set_bits.hpp>
#include <blink/utilities/mask/shift_left.hpp>
#include <blink/utilities/mask/shift_right.hpp>

#include "enums.hpp"

namespace rcc
{
    using utilities::get_bits;
    using utilities::set_bits;
    using utilities::u32_mask_v;

    namespace enum_mask
    {
        enum type : u32
        {
            EXTERNAL_LOW_SPEED_OSCILLATOR_ENABLE = u32_mask_v<0>, // Bit 0: LSEON
            EXTERNAL_LOW_SPEED_OSCILLATOR_READY  = u32_mask_v<1>, // Bit 1: LSERDY
            EXTERNAL_LOW_SPEED_OSCILLATOR_BYPASS = u32_mask_v<2>, // Bit 2: LSEBYP
            EXTERNAL_LOW_SPEED_OSCILLATOR_MODE   = u32_mask_v<3>, // Bit 3: LSEMOD
            // Bits 4:7 Reserved
            RTC_CLOCK_SOURCE_SELECTION = u32_mask_v<8, 9>, // Bits 9:8: RTCSEL[1:0]
            // Bits 10:14 Reserved
            RTC_CLOCK_ENABLE             = u32_mask_v<15>, // Bit 15: RTCEN
            BACKUP_DOMAIN_SOFTWARE_RESET = u32_mask_v<16>, // Bit 16: BDRST
            // Bits 17:31 Reserved
        };
    };

    struct backup_domain_control_register
    {
        constexpr backup_domain_control_register() {}

    private:
        u32 m_value = 0u;
    };

} // namespace rcc
