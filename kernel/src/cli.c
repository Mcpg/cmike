#include <mikeos.h>

void start_cli()
{
    os_print_string("CMike Integrated Shell\r\nType `help` to see available commands.\r\n", DEFAULT_COLOR);

    while(1)
    {
        os_print_string("\r\n> ", DEFAULT_COLOR);
        os_wait_for_key();
    }
}