#pragma once

#include <blink/types.hpp>
#include <blink/utility/mask/count_trailing_zeros.hpp>
#include <blink/utility/mask/get_bits.hpp>
#include <blink/utility/mask/mask.hpp>
#include <blink/utility/mask/set_bits.hpp>
#include <blink/utility/mask/shift_left.hpp>
#include <blink/utility/mask/shift_right.hpp>

#include "enums.hpp"


namespace reset_and_clock_control
{
    using utility::get_bits;
    using utility::set_bits;
    using utility::u32_mask_v;

    namespace enum_mask
    {
        enum type : u32
        {
            INTERNAL_HIGH_SPEED_CLOCK_ENABLE = u32_mask_v<0>,
            INTERNAL_HIGH_SPEED_CLOCK_READY  = u32_mask_v<1>,

            INTERNAL_HIGH_SPEED_CLOCK_TRIMMING    = u32_mask_v<3, 7>,
            INTERNAL_HIGH_SPEED_CLOCK_CALIBRATION = u32_mask_v<8, 15>,

            HIGH_SPEED_EXTERNAL_CLOCK_ENABLE = u32_mask_v<16>,
            HIGH_SPEED_EXTERNAL_CLOCK_READY  = u32_mask_v<17>,

            HIGH_SPEED_EXTERNAL_CLOCK_BYPASS = u32_mask_v<18>,
            CLOCK_SECURITY_SYSTEM_ENABLE     = u32_mask_v<19>,

            PLL_ENABLE = u32_mask_v<24>,
            PLL_READY  = u32_mask_v<25>,

            PLL_I2S_ENABLE = u32_mask_v<26>,
            PLL_I2S_READY  = u32_mask_v<27>,
        };

    }; // namespace enum_mask

    struct clock_control_register
    {
        constexpr clock_control_register() {}

        constexpr enum_enable::type get_internal_high_speed_clock_enable() const noexcept
        {
            /*
            return static_cast<
                enum_ready::
                    type>((m_value & enum_mask::INTERNAL_HIGH_SPEED_CLOCK_ENABLE) >>
            u32_count_trailing_zeros_v<enum_mask::INTERNAL_HIGH_SPEED_CLOCK_ENABLE>);
            */

            // return static_cast<enum_enable::type>(U32_GET_BITS(m_value,
            // enum_mask::INTERNAL_HIGH_SPEED_CLOCK_ENABLE));
            return static_cast<enum_enable::type>(get_bits<enum_mask::INTERNAL_HIGH_SPEED_CLOCK_ENABLE>(m_value));
            // return m_value & enum_mask::INTERNAL_HIGH_SPEED_CLOCK_ENABLE;
        }

        constexpr void set_internal_high_speed_clock_enable(enum_enable::type value) noexcept
        {
            /*
            m_value = ((m_value & ~enum_mask::INTERNAL_HIGH_SPEED_CLOCK_ENABLE) & value);
            */
            set_bits<enum_mask::INTERNAL_HIGH_SPEED_CLOCK_ENABLE>(m_value, value);
            // U32_SET_BITS(m_value, value, enum_mask::INTERNAL_HIGH_SPEED_CLOCK_ENABLE);
        }

        constexpr enum_ready::type get_internal_high_speed_clock_ready() const noexcept
        {
            return static_cast<enum_ready::type>(get_bits<enum_mask::INTERNAL_HIGH_SPEED_CLOCK_ENABLE>(m_value));
        }

        constexpr enum_enable::type get_high_speed_external_clock_enable() const noexcept
        {
            return static_cast<enum_enable::type>(get_bits<enum_mask::HIGH_SPEED_EXTERNAL_CLOCK_ENABLE>(m_value));
        }

        constexpr void set_high_speed_external_clock_enable(enum_enable::type value) const noexcept
        {
            set_bits<enum_mask::HIGH_SPEED_EXTERNAL_CLOCK_ENABLE>(m_value, value);
        }

        constexpr enum_ready::type get_high_speed_external_clock_ready() const noexcept
        {
            return static_cast<enum_ready::type>(get_bits<enum_mask::HIGH_SPEED_EXTERNAL_CLOCK_READY>(m_value));
        }

        constexpr enum_bypass::type get_high_speed_external_clock_bypass() const noexcept
        {
            return static_cast<enum_bypass::type>(get_bits<enum_mask::HIGH_SPEED_EXTERNAL_CLOCK_BYPASS>(m_value));
        }

        constexpr void set_high_speed_external_clock_bypass(enum_bypass::type value) noexcept
        {
            set_bits<enum_mask::HIGH_SPEED_EXTERNAL_CLOCK_BYPASS>(m_value, value);
        }

        constexpr enum_enable::type get_clock_security_system_enable() const noexcept
        {
            return static_cast<enum_enable::type>(get_bits<enum_mask::CLOCK_SECURITY_SYSTEM_ENABLE>(m_value));
        }

        constexpr void set_clock_security_system_enable(enum_enable::type value) noexcept
        {
            set_bits<enum_mask::CLOCK_SECURITY_SYSTEM_ENABLE>(m_value, value);
        }

        constexpr enum_enable::type get_pll_enable()
        {
            return static_cast<enum_enable::type>(get_bits<enum_mask::PLL_ENABLE>(m_value));
        }

        constexpr void set_pll_enable(enum_enable::type value) { set_bits<enum_mask::PLL_ENABLE>(m_value, value); }

        constexpr enum_ready::type get_pll_ready() const noexcept
        {
            return static_cast<enum_ready::type>(get_bits<enum_mask::PLL_READY>(m_value));
        }

        constexpr enum_enable::type get_pll_i2s_enable() const noexcept
        {
            return static_cast<enum_enable::type>(get_bits<enum_mask::PLL_I2S_ENABLE>(m_value));
        }

        constexpr void set_pll_i2s_enable(enum_enable::type value) noexcept
        {
            set_bits<enum_mask::PLL_READY>(m_value, value);
        }

        constexpr enum_ready::type get_pll_i2s_ready() const noexcept
        {
            return static_cast<enum_ready::type>(get_bits<enum_mask::PLL_I2S_READY>(m_value));
        }

        constexpr operator uint32_t() const noexcept { return m_value; }

    private:
        u32 m_value = 0u;
    };

} // namespace reset_and_clock_control