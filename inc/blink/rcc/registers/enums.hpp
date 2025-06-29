#pragma once

#include <blink/types.hpp>

namespace rcc
{
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

    namespace enum_bypass
    {
        enum type : u32
        {
            NOT_BYPASSED,
            BYPASSED,
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

} // namespace rcc