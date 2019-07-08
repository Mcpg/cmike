#include <mikeos.h>

void _os_string_chomp(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_string_chomp((char*) *ax);
}

void os_string_chomp(char* string)
{
    /* os_string_chomp copies the entire string to the beginning, */
    /* and replaces spaces from the end to 0s */

    int leading;
    for (leading = 0; string[leading] != ' '; leading++) ;
    if (leading > 0)
        os_string_copy(&string[leading], string);

    int len = os_string_length(string);
    if (string[len - 1] == ' ')
    {
        for (int i = len - 1; string[i] == ' '; i--)
            string[i] = 0;
    }
}