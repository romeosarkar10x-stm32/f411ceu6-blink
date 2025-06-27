#pragma once

#include <type_traits>

#include "count_trailing_zeros.hpp"

#define U32_SET_BITS(lvalue, rvalue, mask) lvalue = ((lvalue & (~mask)) & rvalue)

namespace utilities
{
    template <auto _Mask, typename T, typename U>
        requires std::is_convertible_v<decltype(_Mask), T> && std::is_convertible_v<U, T>
    void set_bits(T& l_value, const U& r_value)
    {
        l_value = (l_value & (~_Mask)) & (static_cast<T>(r_value) << count_trailing_zeros_v<T, _Mask>);
    }
} // namespace utilities
