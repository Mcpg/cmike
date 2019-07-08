#include <mikeos.h>

void panic(char* text)
{
    os_print_string("A fatal error occurred and CMike had to shut down.\r\nYou need to restart your computer.\r\n\n", DEFAULT_COLOR);
    os_print_string(text, DEFAULT_COLOR);
    HALT();
}
