#include <mikeos.h>

void _os_serial_port_enable(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    if (os_serial_port_enable(*ax))
    {
        *ax = *ax ^ 0x8000;
    }
    else
    {
        *ax = *ax | 0x8000;
    }
}

int os_serial_port_enable(int mode)
{
    return 0;
}
