#include <mikeos.h>

void _os_wait_for_key(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    /* MikeOS returns the ASCII character in al and the scancode in ah */
    *ax = os_wait_for_key() | (((uint16_t) last_scancode) << 8);
}

char last_scancode = 0;

char os_wait_for_key()
{
    uint16_t ax = 0;
    asm volatile("int $0x16" : "=a" (ax) : "a" (ax));
    last_scancode = (ax >> 8) & 0x00FF;
    return ax & 0x00FF; /* Get just al register */
}
