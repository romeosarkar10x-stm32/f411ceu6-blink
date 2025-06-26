#pragma once

#include <blink/types.hpp>
#include <blink/utility/mask/mask.hpp>
#include <blink/utility/mask/shift_left.hpp>

namespace reset_and_clock_control
{
    using utility::u32_mask_v;
    using utility::u32_shift_left_v;

    namespace enum_mask
    {
        enum type : u32
        {
            TIMERS_CLOCKS_PRESCALERS_SELECTION = u32_mask_v<24>,
        };
    }; // namespace enum_mask

    struct dedicated_clocks_configuration_register
    {
        constexpr dedicated_clocks_configuration_register() {}

    private:
        u32 m_value = 0u;
    };

} // namespace reset_and_clock_control