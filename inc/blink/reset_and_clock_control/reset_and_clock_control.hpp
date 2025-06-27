#include <cstdint>

#include "registers/clock_configuration_register.hpp"
#include "registers/clock_control_register.hpp"
#include "registers/clock_interrupt_register.hpp"
#include "registers/peripheral_clock_enable/ahb1_peripheral_clock_enable_register.hpp"
#include "registers/peripheral_clock_enable/ahb2_peripheral_clock_enable_register.hpp"
#include "registers/peripheral_clock_enable/apb1_peripheral_clock_enable_register.hpp"
#include "registers/peripheral_clock_enable/apb2_peripheral_clock_enable_register.hpp"
#include "registers/peripheral_reset/ahb1_peripheral_reset_register.hpp"
#include "registers/peripheral_reset/ahb2_peripheral_reset_register.hpp"
#include "registers/peripheral_reset/apb1_peripheral_reset_register.hpp"
#include "registers/peripheral_reset/apb2_peripheral_reset_register.hpp"
#include "registers/pll_configuration_register.hpp"

namespace reset_and_clock_control
{
    struct reset_and_clock_control_registers
    {
        clock_control_register       clock_control_obj;
        pll_configuration_register   pll_configuration_obj;
        clock_configuration_register clock_configuration_obj;
        clock_interrupt_register     clock_interrupt_obj;

        ahb1_peripheral_reset_register ahb1_peripheral_reset_obj;
        ahb2_peripheral_reset_register ahb2_peripheral_reset_obj;
        apb1_peripheral_reset_register apb1_peripheral_reset_obj;
        apb2_peripheral_reset_register apb2_peripheral_reset_obj;

        ahb1_peripheral_clock_enable_register ahb1_peripheral_clock_enable_obj;
        ahb2_peripheral_clock_enable_register ahb2_peripheral_clock_enable_obj;
        apb1_peripheral_clock_enable_register apb1_peripheral_clock_enable_obj;
        apb2_peripheral_clock_enable_register apb2_peripheral_clock_enable_obj;

        // uint32_t clock_control;
        // uint32_t pll_configuration;
        // uint32_t clock_configuration;
        // uint32_t clock_interrupt;

        // uint32_t ahb1_peripheral_reset;
        // uint32_t ahb2_peripheral_reset;
        // uint32_t apb1_peripheral_reset;
        // uint32_t apb2_peripheral_reset;

        // uint32_t ahb1_peripheral_clock_enable;
        // uint32_t ahb2_peripheral_clock_enable;
        // uint32_t apb1_peripheral_clock_enable;
        // uint32_t apb2_peripheral_clock_enable;

        /*
        uint32_t ahb1_peripheral_clock_enable_in_low_power_mode;
        uint32_t ahb2_peripheral_clock_enable_in_low_power_mode;
        */
    };

} // namespace reset_and_clock_control