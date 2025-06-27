#pragma once

#include <blink/types.hpp>
#include <blink/utilities/mask/get_bits.hpp>
#include <blink/utilities/mask/set_bits.hpp>

#include "enums.hpp"
#include "pin.hpp"

namespace gpio
{
    namespace registers
    {
        using utilities::get_bits;
        using utilities::set_bits;

        struct output_data_register
        {
            constexpr output_data_register() {}

            constexpr u16 get_data() const noexcept { return static_cast<u16>(m_value); }

            constexpr void set_data(u16 value) noexcept
            {
                m_value &= 0xffff0000u;
                m_value |= value;
            }

            template <size_t _Pin> constexpr enum_bit::type get_data(pin<_Pin> pin) const noexcept
            {
                return static_cast<enum_bit::type>(get_bits<1u << _Pin>(m_value));
            }

            template <size_t _Pin> constexpr void set_data(pin<_Pin> pin, enum_bit::type value) noexcept
            {
                set_bits<1u << _Pin>(m_value, value);
            }

        private:
            u32 m_value = 0u;
        };
    } // namespace registers
} // namespace gpio