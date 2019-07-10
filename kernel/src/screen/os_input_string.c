#include <mikeos.h>

#define STRING_LIMIT 255

void _os_input_string(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_input_string((char*) *ax, DEFAULT_COLOR, STRING_LIMIT);
}

void os_input_string(char* buffer, char color, int max_size)
{
    int string_size = 0;
    char key;

    *buffer = 0;

    while ((key = os_wait_for_key()) != 13)
    {
        /* Backspace */
        if (key == 8 && string_size > 0)
        {
            *buffer = 0;
            string_size--; 
            buffer--;
            os_print_string("\b \b", color);
            continue;
        }

        if (string_size == max_size)
        {
            continue;
        }

        /* Check if the character is printable */
        if (key >= ' ' && key <= '~')
        {
            *buffer = key;
            string_size++;
            buffer++;
            cmike_print_char(key, color);
        }
    }

    if (string_size > 0)
    {
        buffer++;
        *buffer = 0;
    }
}
