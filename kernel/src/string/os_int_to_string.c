#include <mikeos.h>

static inline int pow(int base, int power)
{
    if (power == 0)
        return 1;
    for (power--; power > 0; power--)
    {
        base *= base; 
    }
    return base;
}

struct gp_registers _os_int_to_string(struct gp_registers regs)
{
    regs.ax = os_int_to_string(regs.ax);
    return regs;
}

char* os_int_to_string(unsigned int number)
{
    char buffer[6] = {0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 5; i++)
    {
        buffer[i] = (number % 10) + '0';
        number /= 10;
        if (number == 0)
            break;
    }
    os_string_reverse(&buffer);
    return &buffer;
}
