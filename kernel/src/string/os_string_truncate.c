#include <mikeos.h>

void _os_string_truncate(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_string_truncate((char*) *si, *ax);
}

void os_string_truncate(char* string, int n)
{
    string[n] = 0;
}
