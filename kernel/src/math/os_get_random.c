#include <mikeos.h>

void _os_get_random(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    *cx = os_get_random(*ax, *bx);
}

/* https://wiki.osdev.org/Random_Number_Generator */
unsigned int os_get_random(unsigned int low, unsigned int high)
{
    if (low == high)
    {
        return low;
    }
    if (low > high)
    {
        return -1;
    }

    os_random_seed = os_random_seed * 11045 + 12345;
    return (os_random_seed % (high - low + 1)) + low; 
}
