#pragma once

#include <blink/types.hpp>
#include <blink/utility/mask/count_trailing_zeros.hpp>
#include <blink/utility/mask/get_bits.hpp>
#include <blink/utility/mask/mask.hpp>
#include <blink/utility/mask/set_bits.hpp>
#include <blink/utility/mask/shift_left.hpp>
#include <blink/utility/mask/shift_right.hpp>

namespace reset_and_clock_control
{
    using utility::get_bits;
    using utility::set_bits;
    using utility::u32_count_trailing_zeros_v;
    using utility::u32_mask_v;
    using utility::u32_shift_left_v;
    using utility::u32_shift_right_v;

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

    namespace enum_enable
    {
        enum type : u32
        {
            OFF,
            ON,
        };

        constexpr enum_enable::type operator&(u32 a, enum_enable::type b)
        {
            return static_cast<enum_enable::type>(a & static_cast<u32>(b));
        }

        constexpr enum_enable::type operator>>(enum_enable::type a, size_t b)
        {
            return static_cast<enum_enable::type>(static_cast<u32>(a) >> b);
        }

    } // namespace enum_enable

    namespace enum_ready
    {
        enum type : u32
        {
            NOT_READY,
            READY,
        };
    }

    namespace enum_lock
    {
        enum type : u32
        {
            UNLOCKED,
            LOCKED,
        };
    }

    struct clock_control_register
    {
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
            return static_cast<enum_ready::type>(m_value & enum_mask::INTERNAL_HIGH_SPEED_CLOCK_READY);
        }

        constexpr operator uint32_t() const noexcept { return m_value; }

    private:
        u32 m_value;
    };

} // namespace reset_and_clock_control