#pragma once

#include <blink/gpio/pin.hpp>
#include <blink/types.hpp>
#include <blink/utilities/mask/get_bits.hpp>
#include <blink/utilities/mask/set_bits.hpp>

namespace gpio
{
    using utilities::get_bits;
    using utilities::set_bits;

    struct pull_up_pull_down_register
    {
        struct enum_pull_up_pull_down_configuration
        {
            enum type : u32
            {
                NO_PULL_UP_PULL_DOWN,
                PULL_UP,
                PULL_DOWN,
                RESERVED,
            };
        };

        constexpr pull_up_pull_down_register() {}

        template <size_t _Pin>
        constexpr enum_pull_up_pull_down_configuration::type get_configuration(pin<_Pin> pin) const noexcept
        {
            return static_cast<enum_pull_up_pull_down_configuration::type>(get_bits<1u << (_Pin * 2)>(m_value));
        }

        template <size_t _Pin>
        constexpr void set_configuration(pin<_Pin> pin, enum_pull_up_pull_down_configuration::type value) noexcept
        {
            set_bits<1u << (2 * _Pin)>(m_value, value);
        }

    private:
        u32 m_value = 0u;
    };
} // namespace gpio