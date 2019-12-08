OUTPUT_FORMAT(binary)
ENTRY(_start)

SECTIONS
{
    . = 0x8000;

    .text : ALIGN(4) {
        *(.cmike_init)
        *(.text)
    }

    .data : ALIGN(4) {
        *(.data)
        *(.rodata)
        *(.bss)
        *(COMMON)
    }

    _free_space_start = .;
}
