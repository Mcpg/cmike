#include <mikeos.h>

void _os_long_int_negate(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_long_int_negate((int*) *dx, (int*) *ax);
}

void os_long_int_negate(int* hi, int* lo)
{
    /* TODO */
}
