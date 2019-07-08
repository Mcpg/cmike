#include <mikeos.h>

void _os_dump_string(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_dump_string((char*) *si);
}

void os_dump_string(char* string)
{
    
}
