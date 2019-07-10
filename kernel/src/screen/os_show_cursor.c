#include <mikeos.h>

void _os_show_cursor(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_show_cursor();
}

void os_show_cursor()
{
    asm("int $0x10" : : "a" (0x0103), "c" (0x0607));
}
