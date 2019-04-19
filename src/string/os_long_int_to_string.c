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

struct gp_registers _os_long_int_to_string(struct gp_registers regs)
{
    os_long_int_to_string(regs.dx, regs.ax, regs.bx, (char*) regs.di);
    return regs;
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
