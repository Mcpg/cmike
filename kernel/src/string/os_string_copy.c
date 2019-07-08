#include <mikeos.h>

void _os_string_copy(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_string_copy((char*) *si, (char*) *di);
}

void os_string_copy(char* source, char* destination)
{
    for (int i = 0; source[i]; i++)
    {
        destination[i] = source[i];
    }
}
