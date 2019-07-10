#include <mikeos.h>

void _os_hide_cursor(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_hide_cursor();
}

void os_hide_cursor()
{
    asm("int $0x10" : : "a" (0x0103), "c" (0x2000));
}
