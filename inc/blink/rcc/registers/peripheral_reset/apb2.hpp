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
    namespace peripheral_reset
    {
        using utilities::get_bits;
        using utilities::set_bits;
        using utilities::u32_mask_v;

        namespace enum_mask
        {
            enum type : u32
            {
                TIM1_RESET = u32_mask_v<0>, // Bit 0: TIM1RST
                // Bits 1:3 Reserved
                USART1_RESET = u32_mask_v<4>, // Bit 4: USART1RST
                USART6_RESET = u32_mask_v<5>, // Bit 5: USART6RST
                // Bits 6:7 Reserved
                ADC1_RESET = u32_mask_v<8>, // Bit 8: ADC1RST
                // Bits 9:10 Reserved
                SDIO_RESET                            = u32_mask_v<11>, // Bit 11: SDIORST
                SPI1_RESET                            = u32_mask_v<12>, // Bit 12: SPI1RST
                SPI4_RESET                            = u32_mask_v<13>, // Bit 13: SPI4RST
                SYSTEM_CONFIGURATION_CONTROLLER_RESET = u32_mask_v<14>, // Bit 14: SYSCFGRST
                // Bit 15 Reserved
                TIM9_RESET  = u32_mask_v<16>, // Bit 16: TIM9RST
                TIM10_RESET = u32_mask_v<17>, // Bit 17: TIM10RST
                TIM11_RESET = u32_mask_v<18>, // Bit 18: TIM11RST
                // Bit 19 Reserved
                SPI5_RESET = u32_mask_v<20>, // Bit 20: SPI5RST
                // Bits 21:31 Reserved
            };
        };

        struct apb2_peripheral_reset_register
        {
            constexpr apb2_peripheral_reset_register() {}

        private:
            u32 m_value = 0u;
        };
    } // namespace peripheral_reset
} // namespace rcc
