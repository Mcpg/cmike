#include <mikeos.h>

struct gp_registers _os_pause(struct gp_registers regs)
{
    os_pause(regs.ax);
    return regs;
}

void os_pause(unsigned int time)
{
    
}
