#pragma once

#include "type.hpp"

namespace utility
{
    template <size_t _StartBit, size_t _EndBit = _StartBit> struct u32_mask
    {
        static_assert(_StartBit < 32u);
        static_assert(_EndBit < 32u);

        static constexpr u32 value = (0xffffffffu >> (31u - _EndBit)) & (0xffffffffu << _StartBit);
    };

    template <size_t _StartBit, size_t _EndBit = _StartBit>
    constexpr u32 u32_mask_v = u32_mask<_StartBit, _EndBit>::value;

    template <size_t _StartBit, size_t _EndBit = _StartBit> struct u16_mask
    {
        static_assert(_StartBit < 16u);
        static_assert(_EndBit < 16u);

        static constexpr u16 value = (0xffffu >> (15u - _EndBit)) & (0xffffu << _StartBit);
    };

    template <size_t _StartBit, size_t _EndBit = _StartBit>
    constexpr u16 u16_mask_v = u16_mask<_StartBit, _EndBit>::value;

    template <size_t _StartBit, size_t _EndBit = _StartBit> struct u8_mask
    {
        static_assert(_StartBit < 8u);
        static_assert(_EndBit < 8u);

        static constexpr u16 value = (0xffu >> (7u - _EndBit)) & (0xffu << _StartBit);
    };

    template <size_t _StartBit, size_t _EndBit = _StartBit> constexpr u8 u8_mask_v = u8_mask<_StartBit, _EndBit>::value;

    template <typename T> struct corresponding_type
    {};

    template <> struct corresponding_type<u8>
    {
        template <size_t _StartBit, size_t _EndBit> using type = u8_mask<_StartBit, _EndBit>;
    };

    template <> struct corresponding_type<u16>
    {
        template <size_t _StartBit, size_t _EndBit> using type = u16_mask<_StartBit, _EndBit>;
    };

    template <> struct corresponding_type<u32>
    {
        template <size_t _StartBit, size_t _EndBit> using type = u32_mask<_StartBit, _EndBit>;
    };

    template <typename T> using corresponding_type_t = corresponding_type<T>;

    template <typename T, size_t _StartBit, size_t _EndBit = _StartBit>
    struct mask : corresponding_type<T>::template type<_StartBit, _EndBit>
    {};

    template <typename T, size_t _StartBit, size_t _EndBit = _StartBit>
    constexpr T mask_v = mask<T, _StartBit, _EndBit>::value;
} // namespace utility
