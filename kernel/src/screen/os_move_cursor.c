#include <mikeos.h>

struct gp_registers _os_move_cursor(struct gp_registers regs)
{
    os_move_cursor(regs.dx & 0xFF00, regs.dx & 0x00FF);
    return regs;
}

void os_move_cursor(char row, char column)
{
    
}
