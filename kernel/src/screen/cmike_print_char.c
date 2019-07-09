#include <mikeos.h>

void cmike_print_char(char c, char color)
{
    char buffer[2] = {0, 0};
    buffer[0] = c;
    os_print_string(buffer, color);
}
