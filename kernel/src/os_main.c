#include <mikeos.h>

#define WELCOME_COLOR COLOR_CREATE(COLOR_LIGHT_BLUE, COLOR_BLACK)
#define GRAY_COLOR    COLOR_CREATE(COLOR_DARK_GRAY, COLOR_BLACK)
#define DONE_COLOR    COLOR_CREATE(COLOR_LIGHT_GREEN, COLOR_BLACK)

void os_main(uint16_t boot_device)
{   
    os_clear_screen();
    
    /* BIOS service: enable "bright" colors and disable blinking */
    asm("int $0x10" : : "a" (0x1003), "b" (0x0000));

    os_print_string("Welcome to CMike!\r\n", WELCOME_COLOR);
    os_print_horiz_line(SCREEN_LINE_DOUBLE, WELCOME_COLOR);

    /* * Generating a random seed... 0xSEED DONE */
    os_print_string(" * ", GRAY_COLOR);
    os_print_string("Generating a random seed... ", DEFAULT_COLOR);
    os_seed_random();
    os_print_string("0x", GRAY_COLOR);
    os_print_4hex(os_random_seed, GRAY_COLOR);
    os_print_string(" DONE\r\n", DONE_COLOR);

    /* * Initializing disk I/O for boot dev 0xXX... DONE */
    os_print_string(" * ", GRAY_COLOR);
    os_print_string("Initializing disk I/O for boot device ", DEFAULT_COLOR);
    os_print_string("0x", GRAY_COLOR);
    os_print_2hex(boot_device, GRAY_COLOR);
    os_print_string("...", DEFAULT_COLOR);
    cmike_disk_init(boot_device & 0xFF);
    os_print_string(" DONE\r\n", DONE_COLOR);

    /*   * Sectors per track: 0xSCTR */
    os_print_string("   * ", GRAY_COLOR);
    os_print_string("Sectors per track: ", DEFAULT_COLOR);
    os_print_string("0x", GRAY_COLOR);
    os_print_4hex(sectors_per_track, GRAY_COLOR);
    os_print_newline(DEFAULT_COLOR);

    /*   * Heads: 0xHEAD */
    os_print_string("   * ", GRAY_COLOR);
    os_print_string("Heads: ", DEFAULT_COLOR);
    os_print_string("0x", GRAY_COLOR);
    os_print_4hex(disk_heads, GRAY_COLOR);
    os_print_newline(DEFAULT_COLOR);

    char buffer[10];
    
    /* * The current time is: HH:MM XM */
    os_print_string(" * ", GRAY_COLOR);
    os_print_string("The current time is: ", DEFAULT_COLOR);
    os_set_time_fmt(TIME_FORMAT_12HR);
    os_get_time_string(buffer);
    os_print_string(buffer, DONE_COLOR);
    os_print_newline(DEFAULT_COLOR);

    /* * The current date is: YYYY/MM/DD */
    os_print_string(" * ", GRAY_COLOR);
    os_print_string("The current date is: ", DEFAULT_COLOR);
    os_set_date_fmt(DATE_FORMAT_YMD);
    os_get_date_string(buffer);
    os_print_string(buffer, DONE_COLOR);
    os_print_newline(DEFAULT_COLOR);

    os_print_newline(DEFAULT_COLOR);
    start_cli();

    panic("End of os_main reached");
    HALT();
}