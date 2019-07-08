#include <mikeos.h>

void _os_print_1hex(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_print_1hex(*ax & 0x00FF);
}

void os_print_1hex(char number)
{
    
}
