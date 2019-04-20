#include <mikeos.h>

struct gp_registers _os_draw_background(struct gp_registers regs)
{
    os_draw_background(regs.ax, regs.bx, regs.cx);
    return regs;
}

void os_draw_background(int top, int bottom, int color)
{
    
}
