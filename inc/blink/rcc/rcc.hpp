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
        constexpr rcc() {}

        /* Clock control register */
        constexpr clock::clock_control_register& get_clock_control_register() { return m_clock_control_obj; }

        constexpr const clock::clock_control_register& get_clock_control_register() const
        {
            return m_clock_control_obj;
        }

        constexpr void set_clock_control_register(const clock::clock_control_register& value)
        {
            m_clock_control_obj = value;
        }

        /* PLL configuration register */
        constexpr pll::pll_configuration_register& get_pll_configuration_register() { return m_pll_configuration_obj; }

        constexpr const pll::pll_configuration_register& get_pll_configuration_register() const
        {
            return m_pll_configuration_obj;
        }

        /* Clock configuration register */
        constexpr clock::clock_configuration_register& get_clock_configuration_register()
        {
            return m_clock_configuration_obj;
        }
        constexpr const clock::clock_configuration_register& get_clock_configuration_register() const
        {
            return m_clock_configuration_obj;
        }

        /* Clock interrupt register */
        constexpr clock::clock_interrupt_register& get_clock_interrupt_register() { return m_clock_interrupt_obj; }

        constexpr const clock::clock_interrupt_register& get_clock_interrupt_register() const
        {
            return m_clock_interrupt_obj;
        }

        /* AHB1 peripheral reset register */
        constexpr peripheral_reset::ahb1_peripheral_reset_register& get_ahb1_peripheral_reset_register()
        {
            return m_ahb1_peripheral_reset_obj;
        }

        constexpr const peripheral_reset::ahb1_peripheral_reset_register& get_ahb1_peripheral_reset_register() const
        {
            return m_ahb1_peripheral_reset_obj;
        }

        /* AHB2 peripheral reset register */
        constexpr peripheral_reset::ahb2_peripheral_reset_register& get_ahb2_peripheral_reset_register()
        {
            return m_ahb2_peripheral_reset_obj;
        }

        constexpr const peripheral_reset::ahb2_peripheral_reset_register& get_ahb2_peripheral_reset_register() const
        {
            return m_ahb2_peripheral_reset_obj;
        }

        /* APB2 peripheral peripheral reset register */
        constexpr peripheral_reset::apb2_peripheral_reset_register& get_apb2_peripheral_reset_register()
        {
            return m_apb2_peripheral_reset_obj;
        }

        constexpr const peripheral_reset::apb2_peripheral_reset_register& get_apb2_peripheral_reset_register() const
        {
            return m_apb2_peripheral_reset_obj;
        }

        /* ABP1 peripheral reset register */
        constexpr peripheral_reset::apb1_peripheral_reset_register& get_apb1_peripheral_reset_register()
        {
            return m_apb1_peripheral_reset_obj;
        }

        constexpr const peripheral_reset::apb1_peripheral_reset_register& get_apb1_peripheral_reset_register() const
        {
            return m_apb1_peripheral_reset_obj;
        }

        /* AHB1 peripheral clock enable register */
        constexpr peripheral_clock_enable::ahb1_peripheral_clock_enable_register&

        get_ahb1_peripheral_clock_enable_register()
        {
            return m_ahb1_peripheral_clock_enable_obj;
        }

        constexpr const peripheral_clock_enable::ahb1_peripheral_clock_enable_register&
        get_ahb1_peripheral_clock_enable_register() const
        {
            return m_ahb1_peripheral_clock_enable_obj;
        }

        constexpr peripheral_clock_enable::ahb2_peripheral_clock_enable_register&
        get_ahb2_peripheral_clock_enable_register()
        {
            return m_ahb2_peripheral_clock_enable_obj;
        }

        constexpr const peripheral_clock_enable::ahb2_peripheral_clock_enable_register&
        get_ahb2_peripheral_clock_enable_register() const
        {
            return m_ahb2_peripheral_clock_enable_obj;
        }

        constexpr peripheral_clock_enable::apb1_peripheral_clock_enable_register&
        get_apb1_peripheral_clock_enable_register()
        {
            return m_apb1_peripheral_clock_enable_obj;
        }

        constexpr const peripheral_clock_enable::apb1_peripheral_clock_enable_register&
        get_apb1_peripheral_clock_enable_register() const
        {
            return m_apb1_peripheral_clock_enable_obj;
        }

        constexpr peripheral_clock_enable::apb2_peripheral_clock_enable_register&
        get_apb2_peripheral_clock_enable_register()
        {
            return m_apb2_peripheral_clock_enable_obj;
        }

        constexpr const peripheral_clock_enable::apb2_peripheral_clock_enable_register&
        get_apb2_peripheral_clock_enable_register() const
        {
            return m_apb2_peripheral_clock_enable_obj;
        }

        constexpr backup_domain_control_register& get_backup_domain_control_register()
        {
            return m_backup_domain_control_obj;
        }
        constexpr const backup_domain_control_register& get_backup_domain_control_register() const
        {
            return m_backup_domain_control_obj;
        }

        constexpr clock::clock_control_and_status_register& get_clock_control_and_status_register()
        {
            return m_clock_control_and_status_obj;
        }
        constexpr const clock::clock_control_and_status_register& get_clock_control_and_status_register() const
        {
            return m_clock_control_and_status_obj;
        }

        constexpr clock::spread_spectrum_clock_generation_register& get_spread_spectrum_clock_generation_register()
        {
            return m_spread_spectrum_clock_generation_obj;
        }
        constexpr const clock::spread_spectrum_clock_generation_register& get_spread_spectrum_clock_generation_register(
        ) const
        {
            return m_spread_spectrum_clock_generation_obj;
        }

        constexpr pll::i2s::pll_i2s_configuration_register& get_pll_i2s_configuration_register()
        {
            return m_pll_i2s_configuration_obj;
        }
        constexpr const pll::i2s::pll_i2s_configuration_register& get_pll_i2s_configuration_register() const
        {
            return m_pll_i2s_configuration_obj;
        }

        constexpr clock::dedicated_clocks_configuration_register& get_dedicated_clocks_configuration_register()
        {
            return m_dedicated_clocks_configuration_obj;
        }

        constexpr const clock::dedicated_clocks_configuration_register& get_dedicated_clocks_configuration_register(
        ) const
        {
            return m_dedicated_clocks_configuration_obj;
        }

    private:
        clock::clock_control_register       m_clock_control_obj;
        pll::pll_configuration_register     m_pll_configuration_obj;
        clock::clock_configuration_register m_clock_configuration_obj;
        clock::clock_interrupt_register     m_clock_interrupt_obj;

        peripheral_reset::ahb1_peripheral_reset_register m_ahb1_peripheral_reset_obj;
        peripheral_reset::ahb2_peripheral_reset_register m_ahb2_peripheral_reset_obj;

        u32 m_reserved0[2u];

        peripheral_reset::apb1_peripheral_reset_register m_apb1_peripheral_reset_obj;
        peripheral_reset::apb2_peripheral_reset_register m_apb2_peripheral_reset_obj;

        u32 m_reserved1[2u];

        peripheral_clock_enable::ahb1_peripheral_clock_enable_register m_ahb1_peripheral_clock_enable_obj;
        peripheral_clock_enable::ahb2_peripheral_clock_enable_register m_ahb2_peripheral_clock_enable_obj;

        u32 m_reserved2[2u];

        peripheral_clock_enable::apb1_peripheral_clock_enable_register m_apb1_peripheral_clock_enable_obj;
        peripheral_clock_enable::apb2_peripheral_clock_enable_register m_apb2_peripheral_clock_enable_obj;

        u32 m_reserved3[2u];

        peripheral_clock_enable::low_power_mode::ahb1_peripheral_clock_enable_in_low_power_mode
            m_ahb1_peripheral_clock_enable_in_low_power_mode_obj;
        peripheral_clock_enable::low_power_mode::ahb2_peripheral_clock_enable_in_low_power_mode
            m_ahb2_peripheral_clock_enable_in_low_power_mode_obj;

        u32 m_reserved4[2u];

        peripheral_clock_enable::low_power_mode::apb1_peripheral_clock_enable_in_low_power_mode
            m_apb1_peripheral_clock_enable_in_low_power_mode_obj;
        peripheral_clock_enable::low_power_mode::apb2_peripheral_clock_enable_in_low_power_mode
            m_apb2_peripheral_clock_enable_in_low_power_mode_obj;

        u32 m_reserved5[2u];

        backup_domain_control_register m_backup_domain_control_obj;

        clock::clock_control_and_status_register m_clock_control_and_status_obj;

        u32 m_reserved6[2u];

        clock::spread_spectrum_clock_generation_register m_spread_spectrum_clock_generation_obj;

        pll::i2s::pll_i2s_configuration_register m_pll_i2s_configuration_obj;

        u32 m_reserved7[1u];

        clock::dedicated_clocks_configuration_register m_dedicated_clocks_configuration_obj;
    };

} // namespace rcc