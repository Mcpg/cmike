#include <libcmike.h>

void* memcpy(void* dest, void* src, uint16_t n)
{
    uint16_t i;
    for (i = 0; i < n; i++)
    {
        ((uint8_t*) dest)[i] = ((uint8_t*) src)[i];
    }
    return dest;
}

void* memset(void* dest, int val, uint16_t n)
{
    uint16_t i;
    for (i = 0; i < n; i++)
    {
        ((uint8_t*) dest)[i] = val;
    }
    return dest;
}
