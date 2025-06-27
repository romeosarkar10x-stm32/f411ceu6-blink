#pragma once

#include <blink/types.hpp>
#include <blink/utilities/mask/get_bits.hpp>
#include <blink/utilities/mask/set_bits.hpp>

#include "pin.hpp"


namespace gpio
{
    namespace registers
    {
        namespace enum_lock_status
        {
            enum type : u32
            {
                UNLOCKED,
                LOCKED,
            };
        };

        struct configuration_lock_register
        {
            constexpr configuration_lock_register() {}

            void get_lock_status();

        private:
            u32 m_value;
        };
    } // namespace registers
} // namespace gpio