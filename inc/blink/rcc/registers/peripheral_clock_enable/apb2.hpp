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

        namespace enum_mask
        {
            enum type : u32
            {
                TIM1_CLOCK_ENABLE = u32_mask_v<0>, // Bit 0: TIM1EN
                // Bits 1:3 Reserved
                USART1_CLOCK_ENABLE = u32_mask_v<4>, // Bit 4: USART1EN
                USART6_CLOCK_ENABLE = u32_mask_v<5>, // Bit 5: USART6EN
                // Bits 6:7 Reserved
                ADC1_CLOCK_ENABLE = u32_mask_v<8>, // Bit 8: ADC1EN
                // Bits 9:10 Reserved
                SDIO_CLOCK_ENABLE                            = u32_mask_v<11>, // Bit 11: SDIOEN
                SPI1_CLOCK_ENABLE                            = u32_mask_v<12>, // Bit 12: SPI1EN
                SPI4_CLOCK_ENABLE                            = u32_mask_v<13>, // Bit 13: SPI4EN
                SYSTEM_CONFIGURATION_CONTROLLER_CLOCK_ENABLE = u32_mask_v<14>, // Bit 14: SYSCFGEN
                // Bit 15 Reserved
                TIM9_CLOCK_ENABLE  = u32_mask_v<16>, // Bit 16: TIM9EN
                TIM10_CLOCK_ENABLE = u32_mask_v<17>, // Bit 17: TIM10EN
                TIM11_CLOCK_ENABLE = u32_mask_v<18>, // Bit 18: TIM11EN
                // Bit 19 Reserved
                SPI5_CLOCK_ENABLE = u32_mask_v<20>, // Bit 20: SPI5EN
                // Bits 21:31 Reserved
            };
        };

        struct apb2_peripheral_clock_enable_register
        {
            constexpr apb2_peripheral_clock_enable_register() {}

            constexpr u32 get_tim1_clock_enable() const noexcept
            {
                return get_bits<enum_mask::TIM1_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_tim1_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::TIM1_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_usart1_clock_enable() const noexcept
            {
                return get_bits<enum_mask::USART1_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_usart1_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::USART1_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_usart6_clock_enable() const noexcept
            {
                return get_bits<enum_mask::USART6_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_usart6_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::USART6_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_adc1_clock_enable() const noexcept
            {
                return get_bits<enum_mask::ADC1_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_adc1_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::ADC1_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_sdio_clock_enable() const noexcept
            {
                return get_bits<enum_mask::SDIO_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_sdio_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::SDIO_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_spi1_clock_enable() const noexcept
            {
                return get_bits<enum_mask::SPI1_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_spi1_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::SPI1_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_spi4_clock_enable() const noexcept
            {
                return get_bits<enum_mask::SPI4_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_spi4_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::SPI4_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_system_configuration_controller_clock_enable() const noexcept
            {
                return get_bits<enum_mask::SYSTEM_CONFIGURATION_CONTROLLER_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_system_configuration_controller_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::SYSTEM_CONFIGURATION_CONTROLLER_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_tim9_clock_enable() const noexcept
            {
                return get_bits<enum_mask::TIM9_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_tim9_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::TIM9_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_tim10_clock_enable() const noexcept
            {
                return get_bits<enum_mask::TIM10_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_tim10_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::TIM10_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_tim11_clock_enable() const noexcept
            {
                return get_bits<enum_mask::TIM11_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_tim11_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::TIM11_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_spi5_clock_enable() const noexcept
            {
                return get_bits<enum_mask::SPI5_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_spi5_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::SPI5_CLOCK_ENABLE>(m_value, value);
            }

            constexpr operator uint32_t() const noexcept { return m_value; }

        private:
            u32 m_value = 0u;
        };
    } // namespace peripheral_clock_enable
} // namespace rcc
