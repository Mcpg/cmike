#include <mikeos.h>

void _os_dump_registers(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_dump_registers(*ax, *bx, *cx, *dx, *si, *di);
}

void os_dump_registers(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    
}
