OUTPUT_FORMAT(binary)

SECTIONS
{
    . = 0x0000;
    .text : ALIGN(0) {
        *(.call_vector)
        . = ALIGN(0);
        *(.text)
    }
    .data : ALIGN(0) {
        *(.data)
        *(.bss)
    }
    . = 0x6000;
    kernel_disk_buffer = .;
    . = 0x8000;
    program_space = .;
    . = 0x10000;
}
