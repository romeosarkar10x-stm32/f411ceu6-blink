#pragma once

#include <blink/types.hpp>
#include <blink/utilities/mask/mask.hpp>
#include <blink/utilities/mask/shift_left.hpp>

namespace rcc
{
    namespace clock
    {
        using utilities::u32_mask_v;
        using utilities::u32_shift_left_v;

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
    } // namespace clock
} // namespace rcc