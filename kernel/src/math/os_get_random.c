#include <mikeos.h>

void _os_get_random(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    *cx = os_get_random(*ax, *bx);
}

int os_get_random(int low, int high)
{
    /* TODO */
    return 0;
}
