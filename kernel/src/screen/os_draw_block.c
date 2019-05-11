#include <mikeos.h>

struct gp_registers _os_draw_block(struct gp_registers regs)
{
    os_draw_block(regs.bx & 0x00FF,
                regs.dx & 0x00FF,
                (regs.dx >> 8) & 0x0FF,
                regs.si,
                regs.di);
    return regs;
}

void os_draw_block(char color, char start_x, char start_y, char width, char end_y)
{
    
}
