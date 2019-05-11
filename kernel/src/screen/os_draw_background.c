#include <mikeos.h>

struct gp_registers _os_draw_background(struct gp_registers regs)
{
    os_draw_background((char*) regs.ax, (char*) regs.bx, regs.cx);
    return regs;
}

void os_draw_background(char* top, char* bottom, int color)
{
    
}
