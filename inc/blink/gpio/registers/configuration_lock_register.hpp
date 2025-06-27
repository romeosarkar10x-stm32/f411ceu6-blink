#pragma once

#include <blink/gpio/pin.hpp>
#include <blink/types.hpp>
#include <blink/utilities/mask/get_bits.hpp>
#include <blink/utilities/mask/set_bits.hpp>

#include "input_data_register.hpp"

namespace gpio
{
    namespace enum_lock_status
    {
        enum type : u32
        {

        };
    };
    struct configuration_lock_register
    {
        constexpr configuration_lock_register() {}

        void get_lock_status();

    private:
        u32 m_value;
    };
} // namespace gpio