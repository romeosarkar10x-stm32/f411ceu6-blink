#pragma once

#include <blink/gpio/enums.hpp>
#include <blink/gpio/pin.hpp>
#include <blink/types.hpp>
#include <blink/utilities/mask/get_bits.hpp>

namespace gpio
{
    using utilities::get_bits;

    struct input_data_register
    {
        constexpr input_data_register() {}

        constexpr u16 get_data() { return static_cast<u16>(m_value); }

        template <size_t _Pin> constexpr enum_bit::type get_data(pin<_Pin> pin)
        {
            return static_cast<enum_bit::type>(get_bits<1u << _Pin>(m_value));
        }

    private:
        u32 m_value = 0u;
    };
} // namespace gpio