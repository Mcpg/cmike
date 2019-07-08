#include <mikeos.h>

void _os_send_via_serial(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    if (os_send_via_serial(*ax & 0x00FF))
    {
        *ax = *ax ^ 0x8000;
    }
    else
    {
        *ax = *ax | 0x8000;
    }
}

int os_send_via_serial(char byte)
{
    int retval = 0;
    asm("int $0x14" : "=a" (retval) : "a" (0x0100), "d" (0));
    return retval;
}
