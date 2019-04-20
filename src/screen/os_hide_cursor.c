#include <mikeos.h>

struct gp_registers _os_hide_cursor(struct gp_registers regs)
{
    os_hide_cursor();
    return regs;
}

void os_hide_cursor()
{
    
}
