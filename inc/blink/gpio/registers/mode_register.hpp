#pragma once

#include <blink/types.hpp>
#include <blink/utilities/mask/get_bits.hpp>
#include <blink/utilities/mask/set_bits.hpp>

#include "pin.hpp"

namespace gpio
{
    namespace registers
    {
        using utilities::get_bits;
        using utilities::set_bits;

        namespace enum_gpio_mode
        {
            enum type : u32
            {
                INPUT,
                GENERAL_PURPOSE_OUTPUT,
                ALTERNATE_FUNCTION,
                ANALOG
            };
        }

        struct mode_register
        {
            constexpr mode_register() {}

            template <size_t _Pin> constexpr enum_gpio_mode::type get_mode(pin<_Pin> pin)
            {
                return static_cast<enum_gpio_mode::type>(get_bits<0x3u << (2 * _Pin)>(m_value));
            }

            template <size_t _Pin> constexpr void set_mode(pin<_Pin> pin, enum_gpio_mode::type value)
            {
                set_bits<(0x3u << (2 * _Pin))>(m_value, value);
            }

        private:
            u32 m_value = 0u;
        };
    } // namespace registers
} // namespace gpio
