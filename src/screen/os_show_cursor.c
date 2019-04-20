#include <mikeos.h>

struct gp_registers _os_show_cursor(struct gp_registers regs)
{
    os_show_cursor();
    return regs;
}

void os_show_cursor()
{
    
}
