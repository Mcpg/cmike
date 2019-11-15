#include <mikeos.h>

void _os_long_int_negate(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_long_int_negate((int*) *dx, (int*) *ax);
}

void os_long_int_negate(int* hi, int* lo)
{
    uint32_t temp = (uint32_t) (*lo) | ((uint32_t) (*hi) << 16);
    temp = -temp;
    *lo = temp & 0x0000FFFF;
    *hi = (temp >> 16) & 0x0000FFFF;
}
