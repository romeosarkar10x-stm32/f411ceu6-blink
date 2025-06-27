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

        namespace enum_output_type
        {
            enum type : u32
            {
                PUSH_PULL,
                OPEN_DRAIN,
            };
        };

        struct output_type_register
        {
            template <size_t _Pin> enum_output_type::type get_type(pin<_Pin> pin)
            {
                return static_cast<enum_output_type::type>(get_bits<1u << _Pin>(m_value));
            }

            template <size_t _Pin> void set_type(pin<_Pin> pin, enum_output_type::type value)
            {
                set_bits<1u << _Pin>(m_value, value);
            }

        private:
            u32 m_value;
        };
    } // namespace registers
} // namespace gpio