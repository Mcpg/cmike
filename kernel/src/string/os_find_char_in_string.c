#include <mikeos.h>

void _os_find_char_in_string(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    *ax = os_find_char_in_string((char*) *si, *ax & 0x00FF);
}

int os_find_char_in_string(char* string, char ch)
{
    for (int i = 0; string[i]; i++)
    {
        if (string[i] == ch)
        {
            return i;
        }
    }
    return 0;
}
