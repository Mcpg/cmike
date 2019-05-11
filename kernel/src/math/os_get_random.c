#include <mikeos.h>

struct gp_registers _os_get_random(struct gp_registers regs)
{
    regs.cx = os_get_random(regs.ax, regs.bx);
    return regs;
}

int os_get_random(int low, int high)
{
    return 0;
}
