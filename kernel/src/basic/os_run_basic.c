#include <mikeos.h>

struct gp_registers _os_run_basic(struct gp_registers regs)
{
    os_run_basic((char*) regs.ax, regs.bx);
    return regs;
}

void os_run_basic(char* code, int size)
{
    
}
