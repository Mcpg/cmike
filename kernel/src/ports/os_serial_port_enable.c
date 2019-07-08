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
    int retval = 0;
    if (mode == PORT_SERIAL_SLOW_MODE)
    {
        asm("int $0x14" : "=a" (retval) : "a" (0b11100011), "d" (0));
    }
    else if (mode == PORT_SERIAL_NORMAL_MODE)
    {
        asm("int $0x14" : "=a" (retval) : "a" (0b10000011), "d" (0));
    }
    else
    {
        panic("Unknown serial port speed!");
        return 0;
    }
    return retval != 0;
}
