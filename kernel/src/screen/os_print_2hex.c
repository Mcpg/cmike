#include <mikeos.h>

struct gp_registers _os_print_2hex(struct gp_registers regs)
{
    os_print_2hex(regs.ax & 0x00FF);
    return regs;
}

void os_print_2hex(char number)
{
    
}
