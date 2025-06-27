#pragma once

#include <blink/gpio/pin.hpp>
#include <blink/types.hpp>
#include <blink/utilities/mask/get_bits.hpp>
#include <blink/utilities/mask/set_bits.hpp>

namespace gpio
{
    using utilities::get_bits;
    using utilities::set_bits;

    namespace enum_output_speed
    {
        enum type : u32
        {
            LOW,
            MEDIUM,
            FAST,
            HIGH,
        };
    }

    struct output_speed_register
    {
        constexpr output_speed_register() {}

        template <size_t _Pin> constexpr enum_output_speed::type get_speed(pin<_Pin> pin)
        {
            return static_cast<enum_output_speed::type>(get_bits<3u << _Pin>(m_value));
        }

        template <size_t _Pin> constexpr void set_speed(pin<_Pin> pin, enum_output_speed::type value)
        {
            set_bits<3u << _Pin>(m_value, value);
        }

        void set_speed(enum_output_speed::type value)
        {
            // TODO: Implement this!
        }

    private:
        u32 m_value = 0u;
    };
} // namespace gpio
