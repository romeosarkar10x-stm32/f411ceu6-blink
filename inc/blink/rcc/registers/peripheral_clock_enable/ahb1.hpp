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
                GPIOA_CLOCK_ENABLE = u32_mask_v<0>, // Bit 0: GPIOAEN
                GPIOB_CLOCK_ENABLE = u32_mask_v<1>, // Bit 1: GPIOBEN
                GPIOC_CLOCK_ENABLE = u32_mask_v<2>, // Bit 2: GPIOCEN
                GPIOD_CLOCK_ENABLE = u32_mask_v<3>, // Bit 3: GPIODEN
                GPIOE_CLOCK_ENABLE = u32_mask_v<4>, // Bit 4: GPIOEEN
                // Bits 5:6 Reserved
                GPIOH_CLOCK_ENABLE = u32_mask_v<7>, // Bit 7: GPIOHEN
                // Bits 8:11 Reserved
                CRC_CLOCK_ENABLE = u32_mask_v<12>, // Bit 12: CRCEN
                // Bits 13:20 Reserved
                DMA1_CLOCK_ENABLE = u32_mask_v<21>, // Bit 21: DMA1EN
                DMA2_CLOCK_ENABLE = u32_mask_v<22>, // Bit 22: DMA2EN
                // Bits 23:31 Reserved
            };
        };

        struct ahb1_peripheral_clock_enable_register
        {
            constexpr ahb1_peripheral_clock_enable_register() {}

            constexpr u32 get_gpioa_clock_enable() const noexcept
            {
                return get_bits<enum_mask::GPIOA_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_gpioa_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::GPIOA_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_gpiob_clock_enable() const noexcept
            {
                return get_bits<enum_mask::GPIOB_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_gpiob_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::GPIOB_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_gpioc_clock_enable() const noexcept
            {
                return get_bits<enum_mask::GPIOC_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_gpioc_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::GPIOC_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_gpiod_clock_enable() const noexcept
            {
                return get_bits<enum_mask::GPIOD_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_gpiod_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::GPIOD_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_gpioe_clock_enable() const noexcept
            {
                return get_bits<enum_mask::GPIOE_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_gpioe_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::GPIOE_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_gpioh_clock_enable() const noexcept
            {
                return get_bits<enum_mask::GPIOH_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_gpioh_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::GPIOH_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_crc_clock_enable() const noexcept
            {
                return get_bits<enum_mask::CRC_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_crc_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::CRC_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_dma1_clock_enable() const noexcept
            {
                return get_bits<enum_mask::DMA1_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_dma1_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::DMA1_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_dma2_clock_enable() const noexcept
            {
                return get_bits<enum_mask::DMA2_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_dma2_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::DMA2_CLOCK_ENABLE>(m_value, value);
            }

            constexpr operator uint32_t() const noexcept { return m_value; }

        private:
            u32 m_value = 0u;
        };
    } // namespace peripheral_clock_enable
} // namespace rcc
