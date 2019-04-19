#include <mikeos.h>

struct gp_registers _os_sint_to_string(struct gp_registers regs)
{
    regs.ax = os_sint_to_string((int) regs.ax);
    return regs;
}

char* os_sint_to_string(int number)
{
    char buffer[7] = {0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 6; i++)
    {
        if (number < 0 && i == 0)
        {
            buffer[6] = '-';
            number *= -1;
        }
        buffer[i] = (number % 10) + '0';
        number /= 10;
        if (number == 0)
            break;
    }
    os_string_reverse(&buffer);
    return &buffer;
}