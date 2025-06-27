#pragma once

#include <type_traits>

#include "count_trailing_zeros.hpp"

#define U32_GET_BITS(value, mask) ((value & mask) >> u32_count_trailing_zeros_v<mask>)

namespace utilities
{

    template <auto _Mask, typename T>
    constexpr T get_bits(T value)
        requires std::is_convertible_v<decltype(_Mask), T>
    {
        return ((value & static_cast<T>(_Mask)) >> count_trailing_zeros_v<T, _Mask>);
    }
} // namespace utilities