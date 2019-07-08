#include <mikeos.h>

void _os_wait_for_key(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    *ax = os_wait_for_key();
}

char os_wait_for_key()
{
    uint16_t ax = 0;
    asm volatile("int $0x16" : "=a" (ax) : "a" (ax));
    return ax & 0x00FF; /* Get just al register */
}
