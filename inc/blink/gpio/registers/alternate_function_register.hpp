#pragma once

#include <blink/memory_map.hpp>
#include <blink/types.hpp>
#include <blink/utilities/mask/get_bits.hpp>
#include <blink/utilities/mask/set_bits.hpp>

#include "pin.hpp"


namespace gpio
{
    namespace registers
    {
        using utilities::get_bits;
        using utilities::set_bits;
        /*
        template <u32 _Function> struct alternate_function
        {
            static_assert(_Function < 16u);
            static constexpr u32 value = _Function;
        };
        */

        namespace enum_alternate_function
        {
            enum type : u32
            {
                ALTERNATE_FUNCTION_0,
                ALTERNATE_FUNCTION_1,
                ALTERNATE_FUNCTION_2,
                ALTERNATE_FUNCTION_3,
                ALTERNATE_FUNCTION_4,
                ALTERNATE_FUNCTION_5,
                ALTERNATE_FUNCTION_6,
                ALTERNATE_FUNCTION_7,
                ALTERNATE_FUNCTION_8,
                ALTERNATE_FUNCTION_9,
                ALTERNATE_FUNCTION_10,
                ALTERNATE_FUNCTION_11,
                ALTERNATE_FUNCTION_12,
                ALTERNATE_FUNCTION_13,
                ALTERNATE_FUNCTION_14,
                ALTERNATE_FUNCTION_15,
            };
        }

        struct alternate_function_register
        {
            template <size_t _Pin> struct mask
            {
                static_assert(_Pin < 16u);
                static constexpr u32 value = (_Pin >= 8u) ? 15u << ((_Pin - 8u) * 4u) : 15u << (_Pin * 4u);
            };

            template <size_t _Pin> static constexpr u32 mask_v = mask<_Pin>::value;

            template <size_t _Pin> constexpr enum_alternate_function::type get_alternate_function(pin<_Pin> pin)
            {
                return static_cast<enum_alternate_function::type>(
                    get_bits<mask_v<_Pin>>(_Pin >= 8u ? m_value_high : m_value_low)
                );
            }

            template <size_t _Pin>
            constexpr void set_alterate_function(pin<_Pin> pin, enum_alternate_function::type value)
            {
                set_bits<mask_v<_Pin>>(_Pin >= 8u ? m_value_high : m_value_low);
            }

        private:
            u32 m_value_low;
            u32 m_value_high;
        };
    } // namespace registers
} // namespace gpio