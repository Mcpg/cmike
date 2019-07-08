#include <mikeos.h>

void _os_get_via_serial(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    char result;
    if (os_get_via_serial(&result))
    {
        *ax = ((*ax & 0xFF00) ^ 0x8000) | (result & 0xFF);
    }
    else
    {
        *ax = *ax | 0x8000;
    }
}

int os_get_via_serial(char* byte)
{
    int retval = 0;
    asm("int $0x14" : "=a" (retval) : "a" (0x0200), "d" (0));
    *byte = retval & 0xFF;
    return (retval >> 8) & 0xFF;
}
