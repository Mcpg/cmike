#include <mikeos.h>

void cmike_print_dec(int number, char color)
{
    char negative = 0;
    int i = 0;
    char* buffer = "00000";
    
    if (number < 0)
    {
        negative = 1;
        number = -number;
    }

    if (number == 0)
    {
        cmike_print_char(digits[0], color);
        return;
    }

    for (i = 4; i >= 0 && number > 0; i--)
    {
        buffer[i] = digits[number % 10];
        number /= 10;
    }

    if (negative)
    {
        cmike_print_char('-', color);
    }

    buffer += i + 1;
    os_print_string(buffer, color);
}
