#include <mikeos.h>

#define WELCOME_COLOR COLOR_CREATE(COLOR_LIGHT_BLUE, COLOR_BLACK)
#define GRAY_COLOR    COLOR_CREATE(COLOR_DARK_GRAY, COLOR_BLACK)
#define DONE_COLOR    COLOR_CREATE(COLOR_LIGHT_GREEN, COLOR_BLACK)

void os_main(uint16_t boot_device)
{   
    os_clear_screen();

    os_print_string("Welcome to CMike!\r\n", WELCOME_COLOR);
    os_print_horiz_line(SCREEN_LINE_DOUBLE, WELCOME_COLOR);

    os_print_string(" * ", GRAY_COLOR);
    os_print_string("Generating a random seed... ", DEFAULT_COLOR);
    os_seed_random();
    os_print_string("0x", GRAY_COLOR);
    os_print_4hex(os_random_seed, GRAY_COLOR);
    os_print_string(" DONE\r\n", DONE_COLOR);

    os_print_newline(DEFAULT_COLOR);

    start_cli();
    panic("End of os_main reached");
    HALT();
}