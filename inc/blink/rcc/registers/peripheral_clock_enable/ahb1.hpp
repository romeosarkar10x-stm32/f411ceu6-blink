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

        struct ahb1_peripheral_clock_enable_register
        {
            enum enum_mask : u32
            {
                GPIO_A_CLOCK_ENABLE = u32_mask_v<0>,
                GPIO_B_CLOCK_ENABLE = u32_mask_v<1>,
                GPIO_C_CLOCK_ENABLE = u32_mask_v<2>,
                GPIO_D_CLOCK_ENABLE = u32_mask_v<3>,
                GPIO_E_CLOCK_ENABLE = u32_mask_v<4>,
                GPIO_H_CLOCK_ENABLE = u32_mask_v<7>,
                CRC_CLOCK_ENABLE    = u32_mask_v<12>,
                DMA1_CLOCK_ENABLE   = u32_mask_v<21>,
                DMA2_CLOCK_ENABLE   = u32_mask_v<22>,
            };

            constexpr ahb1_peripheral_clock_enable_register() {}

            constexpr u32 get_gpio_a_clock_enable() const noexcept
            {
                return get_bits<enum_mask::GPIO_A_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_gpio_a_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::GPIO_A_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_gpio_b_clock_enable() const noexcept
            {
                return get_bits<enum_mask::GPIO_B_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_gpio_b_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::GPIO_B_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_gpio_c_clock_enable() const noexcept
            {
                return get_bits<enum_mask::GPIO_C_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_gpio_c_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::GPIO_C_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_gpio_d_clock_enable() const noexcept
            {
                return get_bits<enum_mask::GPIO_D_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_gpio_d_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::GPIO_D_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_gpio_e_clock_enable() const noexcept
            {
                return get_bits<enum_mask::GPIO_E_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_gpio_e_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::GPIO_E_CLOCK_ENABLE>(m_value, value);
            }

            constexpr u32 get_gpio_h_clock_enable() const noexcept
            {
                return get_bits<enum_mask::GPIO_H_CLOCK_ENABLE>(m_value);
            }
            constexpr void set_gpio_h_clock_enable(u32 value) noexcept
            {
                set_bits<enum_mask::GPIO_H_CLOCK_ENABLE>(m_value, value);
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
