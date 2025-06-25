#include <cstdint>

#include ""
#include "registers/clock_control_register.hpp"


namespace reset_and_clock_control
{
    struct reset_and_clock_control_registers
    {
        uint32_t clock_control;
        uint32_t pll_configuration;
        uint32_t clock_configuration;
        uint32_t clock_interrupt;

        uint32_t ahb1_peripheral_reset;
        uint32_t ahb2_peripheral_reset;
        uint32_t apb1_peripheral_reset;
        uint32_t apb2_peripheral_reset;

        uint32_t ahb1_peripheral_clock_enable;
        uint32_t ahb2_peripheral_clock_enable;
        uint32_t apb1_peripheral_clock_enable;
        uint32_t apb2_peripheral_clock_enable;

        uint32_t ahb1_peripheral_clock_enable_in_low_power_mode;
        uint32_t ahb2_peripheral_clock_enable_in_low_power_mode;
    };

} // namespace reset_and_clock_control