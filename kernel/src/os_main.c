#include <mikeos.h>

#define WELCOME_COLOR COLOR_CREATE(COLOR_LIGHT_BLUE, COLOR_BLACK, 0)

void os_main(uint16_t boot_device)
{
    os_print_string("Welcome to CMike!\r\n", WELCOME_COLOR);
    os_print_string("-----------------\r\n", WELCOME_COLOR);
    start_cli();
    panic("End of os_main reached");
    HALT();
}