#pragma once

#include <blink/types.hpp>
#include <blink/utilities/mask/count_trailing_zeros.hpp>
#include <blink/utilities/mask/get_bits.hpp>
#include <blink/utilities/mask/mask.hpp>
#include <blink/utilities/mask/set_bits.hpp>
#include <blink/utilities/mask/shift_left.hpp>
#include <blink/utilities/mask/shift_right.hpp>

namespace rcc
{
    namespace clock
    {
        using utilities::get_bits;
        using utilities::set_bits;
        using utilities::u32_mask_v;

        struct clock_interrupt_register
        {
            enum enum_mask : u32
            {
                LSI_READY_INTERRUPT_FLAG    = u32_mask_v<0>, // Bit 0: LSIRDYF
                LSE_READY_INTERRUPT_FLAG    = u32_mask_v<1>, // Bit 1: LSERDYF
                HSI_READY_INTERRUPT_FLAG    = u32_mask_v<2>, // Bit 2: HSIRDYF
                HSE_READY_INTERRUPT_FLAG    = u32_mask_v<3>, // Bit 3: HSERDYF
                PLL_READY_INTERRUPT_FLAG    = u32_mask_v<4>, // Bit 4: PLLRDYF
                PLLI2S_READY_INTERRUPT_FLAG = u32_mask_v<5>, // Bit 5: PLLI2SRDYF
                // Bit 6 Reserved
                CLOCK_SECURITY_SYSTEM_INTERRUPT_FLAG = u32_mask_v<7>,  // Bit 7: CSSF
                LSI_READY_INTERRUPT_ENABLE           = u32_mask_v<8>,  // Bit 8: LSIRDYIE
                LSE_READY_INTERRUPT_ENABLE           = u32_mask_v<9>,  // Bit 9: LSERDYIE
                HSI_READY_INTERRUPT_ENABLE           = u32_mask_v<10>, // Bit 10: HSIRDYIE
                HSE_READY_INTERRUPT_ENABLE           = u32_mask_v<11>, // Bit 11: HSERDYIE
                PLL_READY_INTERRUPT_ENABLE           = u32_mask_v<12>, // Bit 12: PLLRDYIE
                PLLI2S_READY_INTERRUPT_ENABLE        = u32_mask_v<13>, // Bit 13: PLLI2SRDYIE
                // Bits 14:15 Reserved
                LSI_READY_INTERRUPT_CLEAR    = u32_mask_v<16>, // Bit 16: LSIRDYC
                LSE_READY_INTERRUPT_CLEAR    = u32_mask_v<17>, // Bit 17: LSERDYC
                HSI_READY_INTERRUPT_CLEAR    = u32_mask_v<18>, // Bit 18: HSIRDYC
                HSE_READY_INTERRUPT_CLEAR    = u32_mask_v<19>, // Bit 19: HSERDYC
                PLL_READY_INTERRUPT_CLEAR    = u32_mask_v<20>, // Bit 20: PLLRDYC
                PLLI2S_READY_INTERRUPT_CLEAR = u32_mask_v<21>, // Bit 21: PLLI2SRDYC
                // Bit 22 Reserved
                CLOCK_SECURITY_SYSTEM_INTERRUPT_CLEAR = u32_mask_v<23>, // Bit 23: CSSC
                                                                        // Bits 24:31 Reserved
            };
            constexpr clock_interrupt_register() {}

        private:
            u32 m_value = 0u;
        };
    } // namespace clock
} // namespace rcc
