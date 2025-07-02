MEMORY {
    FLASH (RX) : ORIGIN = 0x08000000, LENGTH = 512K
    SRAM (W) : ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS {
    .vector_table : ALIGN(0x4) {
        KEEP(*(.vector_table))
    } >FLASH

    .text : ALIGN(0x4) {
        *(.text)
        *(.text.*)
    } >FLASH

    .rodata : ALIGN(0x4) {
        *(.rodata)
        *(.rodata.*)
    } >FLASH

    _s_data_flash = LOADADDR(.data);

    .data : ALIGN(4) {
        _s_data_sram = .; /* Start of `data` section */

        *(.data)
        *(.data.*)

        . = ALIGN(4);
        _e_data_sram = .; /* End of `data` section */
    } >SRAM AT>FLASH

    .bss : {

    } >SRAM

    /DISCARD/ : {
        *(.comment)
        *(.ARM.attributes)
    }
}
