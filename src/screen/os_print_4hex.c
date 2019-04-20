#include <mikeos.h>

struct gp_registers _os_print_4hex(struct gp_registers regs)
{
    os_print_4hex(regs.ax);
    return regs;
}

void os_print_4hex(int number)
{
    
}
