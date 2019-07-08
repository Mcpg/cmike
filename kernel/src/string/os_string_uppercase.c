#include <mikeos.h>

void _os_string_uppercase(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_string_uppercase((char*) *ax);
}

void os_string_uppercase(char* string)
{
    for (int i = 0; string[i]; i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] -= 32;
        }
    }
}
