#pragma once

#include <blink/types.hpp>
#include <blink/utilities/mask/count_trailing_zeros.hpp>
#include <blink/utilities/mask/get_bits.hpp>
#include <blink/utilities/mask/mask.hpp>
#include <blink/utilities/mask/set_bits.hpp>
#include <blink/utilities/mask/shift_left.hpp>
#include <blink/utilities/mask/shift_right.hpp>

namespace rcc
{
    namespace peripheral_clock_enable
    {
        using utilities::get_bits;
        using utilities::set_bits;
        using utilities::u32_mask_v;

        struct apb1_peripheral_clock_enable_register
        {
            enum enum_mask : u32
            {
                TIM2_CLOCK_ENABLE = u32_mask_v<0>, // Bit 0: TIM2EN
                TIM3_CLOCK_ENABLE = u32_mask_v<1>, // Bit 1: TIM3EN
                TIM4_CLOCK_ENABLE = u32_mask_v<2>, // Bit 2: TIM4EN
                TIM5_CLOCK_ENABLE = u32_mask_v<3>, // Bit 3: TIM5EN
                // Bits 4:10 Reserved
                WINDOW_WATCHDOG_CLOCK_ENABLE = u32_mask_v<11>, // Bit 11: WWDGEN
                // Bits 12:13 Reserved
                SPI2_CLOCK_ENABLE = u32_mask_v<14>, // Bit 14: SPI2EN
                SPI3_CLOCK_ENABLE = u32_mask_v<15>, // Bit 15: SPI3EN
                // Bit 16 Reserved
                USART2_CLOCK_ENABLE = u32_mask_v<17>, // Bit 17: USART2EN
                // Bits 18:20 Reserved
                I2C1_CLOCK_ENABLE = u32_mask_v<21>, // Bit 21: I2C1EN
                I2C2_CLOCK_ENABLE = u32_mask_v<22>, // Bit 22: I2C2EN
                I2C3_CLOCK_ENABLE = u32_mask_v<23>, // Bit 23: I2C3EN
                // Bits 24:27 Reserved
                POWER_INTERFACE_CLOCK_ENABLE = u32_mask_v<28>, // Bit 28: PWREN
                                                               // Bits 29:31 Reserved
            };

            constexpr apb1_peripheral_clock_enable_register() {}

            constexpr u32 get_tim2_clock_enable() const noexcept
            {
                return get_bits<enum_mask::TIM2_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_tim2_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::TIM2_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_tim3_clock_enable() const noexcept
            {
                return get_bits<enum_mask::TIM3_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_tim3_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::TIM3_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_tim4_clock_enable() const noexcept
            {
                return get_bits<enum_mask::TIM4_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_tim4_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::TIM4_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_tim5_clock_enable() const noexcept
            {
                return get_bits<enum_mask::TIM5_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_tim5_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::TIM5_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_window_watchdog_clock_enable() const noexcept
            {
                return get_bits<enum_mask::WINDOW_WATCHDOG_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_window_watchdog_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::WINDOW_WATCHDOG_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_spi2_clock_enable() const noexcept
            {
                return get_bits<enum_mask::SPI2_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_spi2_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::SPI2_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_spi3_clock_enable() const noexcept
            {
                return get_bits<enum_mask::SPI3_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_spi3_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::SPI3_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_usart2_clock_enable() const noexcept
            {
                return get_bits<enum_mask::USART2_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_usart2_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::USART2_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_i2c1_clock_enable() const noexcept
            {
                return get_bits<enum_mask::I2C1_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_i2c1_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::I2C1_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_i2c2_clock_enable() const noexcept
            {
                return get_bits<enum_mask::I2C2_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_i2c2_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::I2C2_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_i2c3_clock_enable() const noexcept
            {
                return get_bits<enum_mask::I2C3_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_i2c3_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::I2C3_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_power_interface_clock_enable() const noexcept
            {
                return get_bits<enum_mask::POWER_INTERFACE_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_power_interface_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::POWER_INTERFACE_CLOCK_ENABLE>(m_value, value);
            }

            constexpr operator uint32_t() const noexcept { return m_value; }

        private:
            u32 m_value = 0u;
        };
    } // namespace peripheral_clock_enable
} // namespace rcc
