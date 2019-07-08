#include <mikeos.h>

static inline char base_convert_i2ch(int base, int digit)
{
    if (digit > 9)
        return digit + '0' + 7;
}

static inline int base_convert_ch2i(int base, char digit)
{
    if (digit > '9')
        return digit - '0' - 7;
}

void _os_long_int_to_string(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_long_int_to_string(*dx, *ax, *bx, (char*) *di);
}

void os_long_int_to_string(int hi, int lo, int base, char* destination)
{
    if (base <= 1 || base > 36)
        return;
    
    unsigned long number = (hi << 16) | lo;
    int i;
    for (i = 0; i < 32; i++)
    {
        destination[i] = base_convert_i2ch(base, number % base);
        number /= base;
        if (number == 0)
            break;
    }
    destination[i] = 0;
    os_string_reverse(destination);
}
