#pragma once

#include <blink/types.hpp>

namespace rcc
{
    namespace peripheral_clock_enable
    {
        namespace low_power_mode
        {
            struct apb1_peripheral_clock_enable_in_low_power_mode
            {
            private:
                u32 m_value;
            };
        } // namespace low_power_mode
    } // namespace peripheral_clock_enable
} // namespace rcc