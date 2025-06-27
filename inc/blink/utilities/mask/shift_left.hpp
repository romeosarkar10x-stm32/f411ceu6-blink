#pragma once

#include <blink/types.hpp>

#include "count_leading_zeros.hpp"

namespace utilities
{
    template <u32 _Value, u32 _Mask> struct u32_shift_left
    {
        static constexpr u32 value = (_Value << u32_count_leading_zeros_v<_Value>);
    };

    template <u32 _Value, u32 _Mask> constexpr u32 u32_shift_left_v = u32_shift_left<_Value, _Mask>::value;
} // namespace utilities