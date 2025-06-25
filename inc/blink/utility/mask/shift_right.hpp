#pragma once

#include <blink/types.hpp>

#include "count_trailing_zeros.hpp"


namespace utility
{
    template <u32 _Value, u32 _Mask> struct u32_shift_right
    {
        static constexpr u32 value = (_Value >> u32_count_trailing_zeros_v<_Mask>);
    };

    template <u32 _Value, u32 _Mask> constexpr u32 u32_shift_right_v = u32_shift_right<_Value, _Mask>::value;
} // namespace utility