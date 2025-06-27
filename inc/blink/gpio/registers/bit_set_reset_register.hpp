#pragma once

#include <blink/types.hpp>
#include <blink/utilities/mask/set_bits.hpp>

#include "enums.hpp"
#include "pin.hpp"

namespace gpio
{
    namespace registers
    {
        struct bit_set_reset_register
        {
            constexpr bit_set_reset_register() {}

            template <size_t _Pin> void bit_set(pin<_Pin> pin) noexcept { set_bits<1u << _Pin>(m_value, enum_bit::ON); }

            template <size_t _Pin> void bit_reset(pin<_Pin> pin) noexcept
            {
                set_bits<1u << (_Pin + 16u)>(m_value, enum_bit::ON);
            }

        private:
            u32 m_value = 0u;
        };
    } // namespace registers
} // namespace gpio