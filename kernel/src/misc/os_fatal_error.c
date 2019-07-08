#include <mikeos.h>

void _os_fatal_error(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_fatal_error((char*) *ax);
}

void os_fatal_error(char* text)
{
    panic(text);
}
