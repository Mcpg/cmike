#include <mikeos.h>

void _os_dump_registers(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_dump_registers(*ax, *bx, *cx, *dx, *si, *di, DEFAULT_COLOR);
}

void os_dump_registers(int* ax, int* bx, int* cx, int* dx, int* si, int* di, char color)
{
    os_print_string("ax = 0x", color);
    os_print_4hex(*ax, color);

    os_print_string(" bx = 0x", color);
    os_print_4hex(*bx, color);

    os_print_string(" cx = 0x", color);
    os_print_4hex(*cx, color);

    os_print_string(" dx = 0x", color);
    os_print_4hex(*dx, color);

    os_print_string(" si = 0x", color);
    os_print_4hex(*si, color);

    os_print_string(" di = 0x\r\n", color);
    os_print_4hex(*di, color);
}
