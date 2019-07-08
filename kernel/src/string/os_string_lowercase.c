#include <mikeos.h>

void _os_string_lowercase(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_string_lowercase((char*) *ax);
}

void os_string_lowercase(char* string)
{
    for (int i = 0; string[i]; i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] += 32;
        }
    }
}
