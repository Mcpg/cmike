#include <mikeos.h>

#define DEBUG_PRINT_EXTENDED_PANIC_INFO

void abort()
{
    panic("abort() called");
}

void panic(char* text)
{
    os_print_string("\r\nA fatal error occurred and CMike had to shut down.\r\nYou need to restart your computer.\r\n\n", DEFAULT_COLOR);
    os_print_string(text, DEFAULT_COLOR);
#ifdef DEBUG_PRINT_EXTENDED_PANIC_INFO
    os_print_string("\r\n\nExtended debug info:\r\n", DEFAULT_COLOR);

    os_print_string("boot dev: 0x", DEFAULT_COLOR);
    os_print_2hex(boot_device, DEFAULT_COLOR);
    os_print_newline(DEFAULT_COLOR);

    os_print_string(" sectors per track: 0x", DEFAULT_COLOR);
    os_print_4hex(sectors_per_track, DEFAULT_COLOR);
    os_print_newline(DEFAULT_COLOR);

    os_print_string(" disk heads: 0x", DEFAULT_COLOR);
    os_print_4hex(disk_heads, DEFAULT_COLOR);
    os_print_newline(DEFAULT_COLOR);

    os_print_string("file not found flag: 0x", DEFAULT_COLOR);
    os_print_2hex(file_not_found_flag, DEFAULT_COLOR);
    os_print_newline(DEFAULT_COLOR);

    os_print_string("last disk error: 0x", DEFAULT_COLOR);
    os_print_2hex(last_disk_error, DEFAULT_COLOR);
    os_print_newline(DEFAULT_COLOR);
#endif
    HALT();
}
