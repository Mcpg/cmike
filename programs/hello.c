#include <libcmike.h>

void main()
{
    char buffer[256] = { 0 };

    os_print_string("Hello there");
    os_print_newline();
    os_input_string(buffer);
}
