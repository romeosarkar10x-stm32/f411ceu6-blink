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
            INTERNAL_LOW_SPEED_OSCILLATOR_ENABLE = u32_mask_v<0>, // Bit 0: LSION
            INTERNAL_LOW_SPEED_OSCILLATOR_READY  = u32_mask_v<1>, // Bit 1: LSIRDY
            // Bits 2:23 Reserved
            REMOVE_RESET_FLAG               = u32_mask_v<24>, // Bit 24: RMVF
            BOR_RESET_FLAG                  = u32_mask_v<25>, // Bit 25: BORRSTF
            PIN_RESET_FLAG                  = u32_mask_v<26>, // Bit 26: PINRSTF
            POR_PDR_RESET_FLAG              = u32_mask_v<27>, // Bit 27: PORRSTF
            SOFTWARE_RESET_FLAG             = u32_mask_v<28>, // Bit 28: SFTRSTF
            INDEPENDENT_WATCHDOG_RESET_FLAG = u32_mask_v<29>, // Bit 29: IWDGRSTF
            WINDOW_WATCHDOG_RESET_FLAG      = u32_mask_v<30>, // Bit 30: WWDGRSTF
            LOW_POWER_RESET_FLAG            = u32_mask_v<31>, // Bit 31: LPWRRSTF
        };
    };

    struct clock_control_and_status_register
    {
        constexpr clock_control_and_status_register() {}

    private:
        u32 m_value = 0u;
    };

} // namespace reset_and_clock_control
