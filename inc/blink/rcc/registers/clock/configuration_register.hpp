#pragma once

#include <locale.h>

#include <blink/types.hpp>
#include <blink/utilities/mask/get_bits.hpp>
#include <blink/utilities/mask/mask.hpp>
#include <blink/utilities/mask/set_bits.hpp>

namespace rcc
{
    namespace clock
    {
        using utilities::u32_mask_v;

        namespace enum_flag
        {
            enum type : u32
            {
                SYSTEM_CLOCK_SWITCH         = u32_mask_v<0, 1>,
                SYSTEM_CLOCK_SWITCH_STATUS  = u32_mask_v<2, 3>,
                AHB_PRESCALER               = u32_mask_v<4, 7>,
                APB1_PRESCALER              = u32_mask_v<10, 12>,
                APB2_PERSCALER              = u32_mask_v<13, 15>,
                HSE_DIVISION_FACTOR_FOR_RTC = u32_mask_v<16, 20u>,
                MCO1_CLOCK_SOURCE_SELECT    = u32_mask_v<21, 22>,
                I2C_SOURCE_CLOCK_SELECT     = u32_mask_v<23>,
                MCO1_PRESCALER              = u32_mask_v<24, 26>,
                MCO2_PRESCALER              = u32_mask_v<27, 29>,
                MCO2_CLOCK_SOURCE_SELECT    = u32_mask_v<30, 31>,
            };
        };

        namespace enum_clock
        {
            enum type : u32
            {
                HSI,
                HSE,
                PLL,
                NA
            };
        }

        namespace enum_ahb_prescaler_factor
        {
            enum type : u32
            {
                DIV_1,
                DIV_2 = 0x8u,
                DIV_4,
                DIV_8,
                DIV_16,
                DIV_64,
                DIV_128,
                DIV_256,
                DIV_512
            };
        }

        namespace enum_apb_prescaler_factor
        {
            enum type : u32
            {
                DIV_1,
                DIV_2 = 0x4,
                DIV_4,
                DIV_8,
                DIV_16,
            };
        }

        namespace enum_mco1_clock_output
        {
            enum type : u32
            {
                HSI,
                LSE,
                HSE,
                PLL,
            };
        }

        namespace enum_mco2_clock_output
        {
            enum type : u32
            {
                SYSTEM_CLOCK,
                PLL_I2S,
                HSE,
                PLL
            };
        }

        struct clock_configuration_register
        {
            constexpr clock_configuration_register() {}

        private:
            u32 m_value = 0u;
        }; // namespace struct clock_configuration_register
    } // namespace clock
} // namespace rcc
