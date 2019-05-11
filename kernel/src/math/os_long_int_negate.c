#include <mikeos.h>

struct gp_registers _os_long_int_negate(struct gp_registers regs)
{
    os_long_int_negate((int*) regs.dx, (int*) regs.ax);
    return regs;
}

void os_long_int_negate(int* hi, int* lo)
{
    
}
