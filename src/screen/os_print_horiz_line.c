#include <mikeos.h>

struct gp_registers _os_print_horiz_line(struct gp_registers regs)
{
    os_print_horiz_line(regs.ax);
    return regs;
}

void os_print_horiz_line(int line_type)
{
    
}
