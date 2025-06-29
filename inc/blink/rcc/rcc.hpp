#include <cstdint>

#include "registers/backup_domain_control_register.hpp"
#include "registers/clock/spread_spectrum_clock_generation_register.hpp"
#include "registers/peripheral_clock_enable/low_power_mode/ahb1.hpp"
#include "registers/pll/i2s/pll_i2s_configuration_register.hpp"
#include "registers/registers.hpp"

namespace rcc
{
    struct rcc
    {
        clock::clock_control_register       m_clock_control_obj;
        pll::pll_configuration_register     m_pll_configuration_obj;
        clock::clock_configuration_register m_clock_configuration_obj;
        clock::clock_interrupt_register     m_clock_interrupt_obj;

        peripheral_reset::ahb1_peripheral_reset_register m_ahb1_peripheral_reset_obj;
        peripheral_reset::ahb2_peripheral_reset_register m_ahb2_peripheral_reset_obj;
        peripheral_reset::apb1_peripheral_reset_register m_apb1_peripheral_reset_obj;
        peripheral_reset::apb2_peripheral_reset_register m_apb2_peripheral_reset_obj;

        peripheral_clock_enable::ahb1_peripheral_clock_enable_register m_ahb1_peripheral_clock_enable_obj;
        peripheral_clock_enable::ahb2_peripheral_clock_enable_register m_ahb2_peripheral_clock_enable_obj;
        peripheral_clock_enable::apb1_peripheral_clock_enable_register m_apb1_peripheral_clock_enable_obj;
        peripheral_clock_enable::apb2_peripheral_clock_enable_register m_apb2_peripheral_clock_enable_obj;

        peripheral_clock_enable::low_power_mode::ahb1_peripheral_clock_enable_in_low_power_mode
            m_ahb1_peripheral_clock_enable_in_low_power_mode_obj;
        peripheral_clock_enable::low_power_mode::ahb2_peripheral_clock_enable_in_low_power_mode
            m_ahb2_peripheral_clock_enable_in_low_power_mode_obj;
        peripheral_clock_enable::low_power_mode::apb1_peripheral_clock_enable_in_low_power_mode
            m_apb1_peripheral_clock_enable_in_low_power_mode_obj;
        peripheral_clock_enable::low_power_mode::apb2_peripheral_clock_enable_in_low_power_mode
            m_apb2_peripheral_clock_enable_in_low_power_mode_obj;

        backup_domain_control_register m_backup_domain_control_obj;

        clock::clock_control_and_status_register         m_clock_control_and_status_obj;
        clock::spread_spectrum_clock_generation_register m_spread_spectrum_clock_generation_obj;

        pll::i2s::pll_i2s_configuration_register m_pll_i2s_configuration_obj;
    };

} // namespace rcc