#pragma once

#include <blink/types.hpp>

namespace gpio
{
    template <size_t _Pin = 0u> struct pin
    {
        static_assert(_Pin < 16u);
        static constexpr size_t value = _Pin;
    };

} // namespace gpio