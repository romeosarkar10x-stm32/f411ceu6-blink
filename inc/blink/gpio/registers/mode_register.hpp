#pragma once

#include <blink/gpio/pin.hpp>
#include <blink/types.hpp>
#include <blink/utilities/mask/get_bits.hpp>
#include <blink/utilities/mask/set_bits.hpp>

namespace gpio
{
    using utilities::get_bits;
    using utilities::set_bits;

    namespace enum_gpio_mode
    {
        enum type : u32
        {
            GPIO_MODE_INPUT,
            GPIO_MODE_GENERAL_PURPOSE_OUTPUT,
            GPIO_MODE_ALTERNATE_FUNCTION,
            GPIO_MODE_ANALOG
        };
    }

    struct mode_register
    {
        constexpr mode_register() {}

        template <size_t _Pin> constexpr enum_gpio_mode::type get_mode(pin<_Pin> pin)
        {
            return static_cast<enum_gpio_mode::type>(get_bits<0x3u << (2 * _Pin)>(m_value));
        }

        template <size_t _Pin> constexpr void set_mode(pin<_Pin> pin) { set_bits<(0x3u << (2 * _Pin))>(m_value, pin); }

    private:
        u32 m_value = 0u;
    };

} // namespace gpio
