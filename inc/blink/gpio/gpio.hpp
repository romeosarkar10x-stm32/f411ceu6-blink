#pragma once

#include <blink/memory_map.hpp>
#include <blink/types.hpp>

#include "registers/registers.hpp"

namespace gpio
{
    using namespace registers;

    struct gpio
    {
        constexpr gpio() noexcept {}

        constexpr mode_register&       get_mode_register() noexcept { return m_mode_register_obj; }
        constexpr const mode_register& get_mode_register() const noexcept { return m_mode_register_obj; }

        constexpr output_type_register&       get_output_type_register() noexcept { return m_output_type_register_obj; }
        constexpr const output_type_register& get_output_type_register() const noexcept
        {
            return m_output_type_register_obj;
        }

        constexpr output_speed_register& get_output_speed_register() noexcept { return m_output_speed_register_obj; }
        constexpr const output_speed_register& get_output_speed_register() const noexcept
        {
            return m_output_speed_register_obj;
        }

        constexpr pull_up_pull_down_register& get_pull_up_pull_down_register() noexcept
        {
            return m_pull_up_pull_down_register_obj;
        }
        constexpr const pull_up_pull_down_register& get_pull_up_pull_down_register() const noexcept
        {
            return m_pull_up_pull_down_register_obj;
        }

        constexpr input_data_register&       get_input_data_register() noexcept { return m_input_data_register_obj; }
        constexpr const input_data_register& get_input_data_register() const noexcept
        {
            return m_input_data_register_obj;
        }

        constexpr output_data_register&       get_output_data_register() noexcept { return m_output_data_register_obj; }
        constexpr const output_data_register& get_output_data_register() const noexcept
        {
            return m_output_data_register_obj;
        }

        constexpr bit_set_reset_register& get_bit_set_reset_register() noexcept { return m_bit_set_reset_register_obj; }
        constexpr const bit_set_reset_register& get_bit_set_reset_register() const noexcept
        {
            return m_bit_set_reset_register_obj;
        }

        constexpr configuration_lock_register& get_configuration_lock_register() noexcept
        {
            return m_configuration_lock_register_obj;
        }
        constexpr const configuration_lock_register& get_configuration_lock_register() const noexcept
        {
            return m_configuration_lock_register_obj;
        }

        constexpr alternate_function_register& get_alternate_function_register() noexcept
        {
            return m_alternate_function_register_obj;
        }
        constexpr const alternate_function_register& get_alternate_function_register() const noexcept
        {
            return m_alternate_function_register_obj;
        }

    private:
        mode_register              m_mode_register_obj;
        output_type_register       m_output_type_register_obj;
        output_speed_register      m_output_speed_register_obj;
        pull_up_pull_down_register m_pull_up_pull_down_register_obj;

        input_data_register  m_input_data_register_obj;
        output_data_register m_output_data_register_obj;

        bit_set_reset_register      m_bit_set_reset_register_obj;
        configuration_lock_register m_configuration_lock_register_obj;
        alternate_function_register m_alternate_function_register_obj;
    };

} // namespace gpio