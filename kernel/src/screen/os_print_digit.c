#include <mikeos.h>

struct gp_registers _os_print_digit(struct gp_registers regs)
{
    os_print_digit(regs.ax);
    return regs;
}

void os_print_digit(int digit)
{
    
}
