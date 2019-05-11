OUTPUT_FORMAT(binary)

SECTIONS
{
    . = 0x0000;
    .text : {
        *(.call_vector)
        *(.text)
    }
    .data : {
        *(.data)
        *(.bss)
    }
    . = 0x6000;
    kernel_disk_buffer = .;
    . = 0x8000;
    program_space = .;
    . = 0x10000;
}
