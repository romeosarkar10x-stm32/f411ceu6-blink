#pragma once

#include <type_traits>

#include <blink/types.hpp>

namespace utilities
{
    template <u32 _Value> struct is_power_of_2 : std::bool_constant<false>
    {};

    template <> struct is_power_of_2<1u> : std::bool_constant<true>
    {};

    template <> struct is_power_of_2<0u> : std::bool_constant<true>
    {};

    template <u32 _Value>
        requires((_Value & 1u) == 0)
    struct is_power_of_2<_Value> : std::bool_constant<is_power_of_2<(_Value >> 1u)>::value>
    {};

    template <u32 _Value> static constexpr bool is_power_of_2_v = is_power_of_2<_Value>::value;
} // namespace utilities