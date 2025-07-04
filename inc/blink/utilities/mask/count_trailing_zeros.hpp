#pragma once

#include <type_traits>

#include <blink/types.hpp>


namespace utilities
{
    /* u32 */
    template <u32 _Value, size_t _Bit = 0u> struct u32_count_trailing_zeros
    {
        static constexpr size_t value = u32_count_trailing_zeros<_Value, _Bit + 1u>::value;
    };

    template <size_t _Bit> struct u32_count_trailing_zeros<0u, _Bit>
    {
        static constexpr size_t value = 32u;
    };

    template <u32 _Value, size_t _Bit>
        requires((_Value & (1u << _Bit)) != 0u)
    struct u32_count_trailing_zeros<_Value, _Bit>
    {
        static constexpr size_t value = _Bit;
    };

    template <u32 _Value> constexpr size_t u32_count_trailing_zeros_v = u32_count_trailing_zeros<_Value>::value;
    /* *** *** *** *** *** */

    /* u16 */
    template <u16 _Value, size_t _Bit = 0u> struct u16_count_trailing_zeros
    {
        static constexpr size_t value = (_Value == 0)             ? 16u
                                        : (_Value & (1u << _Bit)) ? _Bit
                                                                  : u16_count_trailing_zeros<_Value, _Bit + 1u>::value;
    };

    template <u16 _Value> constexpr size_t u16_count_trailing_zeros_v = u16_count_trailing_zeros<_Value>::value;
    /* *** *** *** *** *** */

    /* u8 */
    template <u8 _Value, size_t _Bit = 0u> struct u8_count_trailing_zeros
    {
        static constexpr size_t value = (_Value == 0)             ? 8u
                                        : (_Value & (1u << _Bit)) ? _Bit
                                                                  : u8_count_trailing_zeros<_Value, _Bit + 1u>::value;
    };

    template <u8 _Value> constexpr size_t u8_count_trailing_zeros_v = u8_count_trailing_zeros<_Value>::value;
    /* *** *** *** *** *** */

    template <typename T> struct corresponding_count_trailing_zeros_type
    {};

    template <> struct corresponding_count_trailing_zeros_type<u32>
    {
        template <u32 _Value> using type = u32_count_trailing_zeros<_Value>;
    };

    template <> struct corresponding_count_trailing_zeros_type<u16>
    {
        template <u16 _Value> using type = u16_count_trailing_zeros<_Value>;
    };

    template <> struct corresponding_count_trailing_zeros_type<u8>
    {
        template <u8 _Value> using type = u8_count_trailing_zeros<_Value>;
    };

    template <typename T>
    using corresponding_count_trailing_zeros_type_t =
        corresponding_count_trailing_zeros_type<std::remove_cvref_t<T>>::type;

    template <typename T, T _Value>
    using count_trailing_zeros = corresponding_count_trailing_zeros_type<T>::template type<_Value>;

    template <typename T, T _Value> constexpr size_t count_trailing_zeros_v = count_trailing_zeros<T, _Value>::value;

} // namespace utilities