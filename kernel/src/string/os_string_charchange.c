#include <mikeos.h>

void _os_string_charchange(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_string_charchange((char*) *si, *ax & 0x00FF, *bx & 0x00FF);
}

void os_string_charchange(char* string, char original, char replacement)
{
    for (int i = 0; string[i]; i++)
    {
        if (string[i] == original)
        {
            string[i] = replacement;
        }
    }
}
