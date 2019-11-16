OUTPUT_FORMAT(binary)

SECTIONS
{
	. = 0x8000;

	.text : ALIGN(0) {
		*(.cmike_init)
		*(.text)
		*(.data)
		*(.rodata)
		*(.bss)
		*(COMMON)
	}
}
