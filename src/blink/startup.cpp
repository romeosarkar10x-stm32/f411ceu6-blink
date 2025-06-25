#include <stdint.h>

#include <blink/main.hpp>

#define SRAM_START 0x20000000
#define SRAM_SIZE  0x00020000 // 128KB
#define SRAM_END   (SRAM_START + SRAM_SIZE)

#define STACK_START SRAM_END

typedef void (*handler_t)(void);

typedef struct
{
    uint32_t  stack_pointer;
    handler_t reset;
    handler_t non_maskable_interrupt;
    handler_t hard_fault;
    handler_t memory_management;
    handler_t bus_fault;
    handler_t usage_fault;

    uint32_t reserved_1[4U];

    handler_t system_service_call;
    handler_t debug_monitor;

    uint32_t reserved_2;

    handler_t pendable_request;
    handler_t systick;

    /* External interrupts */
    handler_t window_watchdog_interrupt;

    handler_t external_interrupt_line_16_or_programmable_voltage_detector;
    handler_t external_interrupt_line_21_or_tamper_and_timestamp_interrupt;
    handler_t external_interrupt_line_22_rtc_wakeup_interrupt;

    handler_t flash_global_interrupt;
    handler_t rcc_global_interrupt; // RCC: Reset and Clock Control

    handler_t external_interrupt_line_0;
    handler_t external_interrupt_line_1;
    handler_t external_interrupt_line_2;
    handler_t external_interrupt_line_3;
    handler_t external_interrupt_line_4;

    handler_t dma1_stream_0_global_interrupt;
    handler_t dma1_stream_1_global_interrupt;
    handler_t dma1_stream_2_global_interrupt;
    handler_t dma1_stream_3_global_interrupt;
    handler_t dma1_stream_4_global_interrupt;
    handler_t dma1_stream_5_global_interrupt;
    handler_t dma1_stream_6_global_interrupt;

    handler_t adc1_global_interrupt;

    uint32_t reserved_3[4U];

    handler_t external_interrupt_line_9_5;

    handler_t tim1_break_and_tim9_global_interrupt;
    handler_t tim1_update_and_tim10_global_interrupt;

    handler_t tim1_trigger_and_commutation_interrupt_and_tim11_global_interrupt;
    handler_t tim1_capture_compare_interrupt;
    handler_t tim2_global_interrupt;
    handler_t tim3_global_interrupt;
    handler_t tim4_global_interrupt;

    handler_t i2c1_event_interrupt;
    handler_t i2c1_error_interrupt;

    handler_t i2c2_event_interrupt;
    handler_t i2c2_error_interrupt;

    handler_t spi1_global_interrupt;
    handler_t spi2_global_interrupt;

    handler_t usart1_global_interrupt;
    handler_t usart2_global_interrupt;

    uint32_t reserved_4;

    handler_t external_interrupt_line_15_10;

    handler_t external_interrupt_line_17_or_rtc_alarms_a_and_b;
    handler_t external_interrupt_line_18_or_usb_on_the_go_fs_wakeup;

    uint32_t reserved_5[4U];

    handler_t dma1_stream_7_global_interrupt;

    uint32_t reserved_6;

    handler_t sdio_global_interrupt;
    handler_t tim5_global_interrupt;
    handler_t spi3_global_interrupt;

    uint32_t reserved_7[4U];

    handler_t dma2_stream0_global_interrupt;
    handler_t dma2_stream1_global_interrupt;
    handler_t dma2_stream2_global_interrupt;
    handler_t dma2_stream3_global_interrupt;
    handler_t dma2_stream4_global_interrupt;

    uint32_t reserved_8[6U];

    handler_t usb_on_the_go_fs_interrupt;

    handler_t dma2_stream5_global_interrupt;
    handler_t dma2_stream6_global_interrupt;
    handler_t dma2_stream7_global_interrupt;

    handler_t usart6_global_interrupt;

    handler_t i2c3_event_interrupt;
    handler_t i2c3_error_interrupt;

    uint32_t reserved_9[7U];

    handler_t fpu_global_interrupt;

    uint32_t reserved_10[2U];

    handler_t spi4_global_interrupt;
    handler_t spi5_global_interrupt;
} vector_table_t;

extern void* _s_data_sram;
extern void* _e_data_sram;

extern void* _s_data_flash;

void copy_data_section_from_flash_to_sram()
{
    asm("LOOP_%=:\n\t"
        "cmp %2, %0\n\t"
        "beq LOOP_END_%=\n\t"
        "ldr r3, [%1]\n\t"
        "str r3, [%0]\n\t"
        "add %1, %1, #4\n\t"
        "add %0, %0, #4\n\t"
        "b LOOP_%=\n\t"
        "LOOP_END_%=:\n\t"
        : "+r"(_s_data_sram), "+r"(_s_data_flash)
        : "r"(_e_data_sram)
        : "r3", "memory");
    /*
    asm("mov r3, #0\n\t"
        "LOOP_%=:\n\t"
        "add r4, r3, %0\n\t"
        "cmp %1, r4\n\t"
        "beq LOOP_END_%=\n\t"
        "ldr r4, [%0 r3]\n\t"
        "str r4, [%2, r3]\n\t"
        "add r3, r3, #4\n\t"
        "b LOOP_%=\n\t"
        "LOOP_END_%=:\n\t"
        :
        : "r"(_s_sram_data), "r"(_e_sram_data), "r"(_s_flash_data)
        : "r3", "r4");
    */
}

void __attribute__((noreturn)) reset_handler()
{
    copy_data_section_from_flash_to_sram();
    main();
}

void __attribute__((weak)) non_maskable_interrupt_handler() {}

void __attribute__((weak)) hard_fault_handler() {}

void __attribute__((weak)) memory_management_handler() {}

void __attribute__((weak)) bus_fault_handler() {}

void __attribute__((weak)) usage_fault_handler() {}

void __attribute__((weak)) system_service_call_handler() {}

void __attribute__((weak)) debug_monitor_handler() {}

void __attribute__((weak)) pendable_request_handler() {}

void __attribute__((weak)) window_watchdog_interrupt_handler() {}

void __attribute__((weak)) default_handler() {}

const vector_table_t __attribute__((section(".vector_table"))) vector_table = {
    .stack_pointer          = STACK_START,
    .reset                  = reset_handler,
    .non_maskable_interrupt = non_maskable_interrupt_handler,
    .hard_fault             = hard_fault_handler,
    .memory_management      = memory_management_handler,
    .bus_fault              = bus_fault_handler,
    .usage_fault            = usage_fault_handler,

    .system_service_call = default_handler,
    .debug_monitor       = default_handler,

    .pendable_request = default_handler,
    .systick          = default_handler,

    /* External interrupts */
    .window_watchdog_interrupt = default_handler,

    .external_interrupt_line_16_or_programmable_voltage_detector  = default_handler,
    .external_interrupt_line_21_or_tamper_and_timestamp_interrupt = default_handler,
    .external_interrupt_line_22_rtc_wakeup_interrupt              = default_handler,

    .flash_global_interrupt = default_handler,
    .rcc_global_interrupt   = default_handler,

    .external_interrupt_line_0 = default_handler,
    .external_interrupt_line_1 = default_handler,
    .external_interrupt_line_2 = default_handler,
    .external_interrupt_line_3 = default_handler,
    .external_interrupt_line_4 = default_handler,

    .dma1_stream_0_global_interrupt = default_handler,
    .dma1_stream_1_global_interrupt = default_handler,
    .dma1_stream_2_global_interrupt = default_handler,
    .dma1_stream_3_global_interrupt = default_handler,
    .dma1_stream_4_global_interrupt = default_handler,
    .dma1_stream_5_global_interrupt = default_handler,
    .dma1_stream_6_global_interrupt = default_handler,

    .adc1_global_interrupt = default_handler,

    .external_interrupt_line_9_5 = default_handler,

    .tim1_break_and_tim9_global_interrupt                              = default_handler,
    .tim1_update_and_tim10_global_interrupt                            = default_handler,
    .tim1_trigger_and_commutation_interrupt_and_tim11_global_interrupt = default_handler,
    .tim1_capture_compare_interrupt                                    = default_handler,

    .tim2_global_interrupt = default_handler,
    .tim3_global_interrupt = default_handler,
    .tim4_global_interrupt = default_handler,

    .i2c1_event_interrupt = default_handler,
    .i2c1_error_interrupt = default_handler,

    .i2c2_event_interrupt = default_handler,
    .i2c2_error_interrupt = default_handler,

    .spi1_global_interrupt = default_handler,
    .spi2_global_interrupt = default_handler,

    .usart1_global_interrupt = default_handler,
    .usart2_global_interrupt = default_handler,

    .external_interrupt_line_15_10                         = default_handler,
    .external_interrupt_line_17_or_rtc_alarms_a_and_b      = default_handler,
    .external_interrupt_line_18_or_usb_on_the_go_fs_wakeup = default_handler,

    .dma1_stream_7_global_interrupt = default_handler,

    .sdio_global_interrupt = default_handler,

    .tim5_global_interrupt = default_handler,

    .spi3_global_interrupt = default_handler,

    .dma2_stream0_global_interrupt = default_handler,
    .dma2_stream1_global_interrupt = default_handler,
    .dma2_stream2_global_interrupt = default_handler,
    .dma2_stream3_global_interrupt = default_handler,
    .dma2_stream4_global_interrupt = default_handler,

    .usb_on_the_go_fs_interrupt = default_handler,

    .dma2_stream5_global_interrupt = default_handler,
    .dma2_stream6_global_interrupt = default_handler,
    .dma2_stream7_global_interrupt = default_handler,

    .usart6_global_interrupt = default_handler,

    .i2c3_event_interrupt = default_handler,
    .i2c3_error_interrupt = default_handler,

    .fpu_global_interrupt = default_handler,

    .spi4_global_interrupt = default_handler,
    .spi5_global_interrupt = default_handler,
};
