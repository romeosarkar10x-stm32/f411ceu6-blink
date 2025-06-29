#pragma once

#include <blink/types.hpp>
#include <blink/utilities/mask/mask.hpp>

namespace rcc
{
    namespace pll
    {
        using utilities::u32_mask_v;

        namespace enum_mask
        {
            enum type : u32
            {
                PLL_M      = u32_mask_v<0u, 5u>,
                PLL_N      = u32_mask_v<6u, 14u>,
                PLL_P      = u32_mask_v<16u, 17u>,
                PLL_SOURCE = u32_mask_v<22u>,
                PLL_Q      = u32_mask_v<24u, 27u>,
            };
        };

        struct pll_configuration_register
        {
            constexpr pll_configuration_register() {}

        private:
            u32 m_value = 0u;
        };
    } // namespace pll
} // namespace rcc