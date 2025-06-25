#pragma once

#include <blink/types.hpp>

namespace utility
{
    template <u32 _Value, size_t _Bit = 0u> struct u32_count_leading_zeros
    {
        static constexpr size_t value = u32_count_leading_zeros<_Value, _Bit + 1u>::value;
    };

    template <size_t _Bit> struct u32_count_leading_zeros<0u, _Bit>
    {
        static constexpr size_t value = 0u;
    };

    template <u32 _Value, size_t _Bit>
        requires((_Value & (0x80000000 >> _Bit)) != 0)
    struct u32_count_leading_zeros<_Value, _Bit>
    {
        static constexpr size_t value = _Bit;
    };

    template <u32 _Value> constexpr size_t u32_count_leading_zeros_v = u32_count_leading_zeros<_Value>::value;

} // namespace utility