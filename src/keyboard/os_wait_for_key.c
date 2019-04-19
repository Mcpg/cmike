#include <mikeos.h>

struct gp_registers _os_wait_for_key(struct gp_registers regs)
{
    regs.ax = os_wait_for_key();
    return regs;
}

char os_wait_for_key()
{
    struct gp_registers regs;
    regs.ax = 0;
    int16h(&regs);
    return regs.ax & 0x00FF; /* Retrive just al register */
}
