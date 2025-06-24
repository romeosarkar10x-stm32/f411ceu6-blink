#include <cstdint>

#include "utility/mask.hpp"

namespace reset_and_clock_control
{
    namespace enum_mask
    {

        using utility::u32_mask_v;

        enum type : uint32_t
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
        enum type : uint32_t
        {
            OFF,
            ON,
        };
    }

    namespace enum_ready
    {
        enum type : uint32_t
        {
            NOT_READY,
            READY,
        };
    }

    namespace enum_lock
    {
        enum type : uint32_t
        {
            UNLOCKED,
            LOCKED,
        };
    }

    struct clock_control_register
    {
        constexpr enum_ready::type get_internal_high_speed_clock_enable() const noexcept
        {
            return static_cast<enum_ready::type>(m_value & enum_mask::INTERNAL_HIGH_SPEED_CLOCK_ENABLE);
        }

        constexpr void set_internal_high_speed_clock_enable(enum_enable::type value) noexcept
        {
            m_value = ((m_value & ~enum_mask::INTERNAL_HIGH_SPEED_CLOCK_ENABLE) & value);
        }

        constexpr enum_enable::type get_internal_high_speed_clock_ready() const noexcept
        {
            return static_cast<enum_enable::type>(m_value & enum_mask::INTERNAL_HIGH_SPEED_CLOCK_READY);
        }

    private:
        uint32_t m_value;
    };

} // namespace reset_and_clock_control