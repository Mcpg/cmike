#include <mikeos.h>

struct gp_registers _os_get_cursor_pos(struct gp_registers regs)
{
    char row, column;
    os_get_cursor_pos(&row, &column);
    regs.dx = ((int) row << 8) | (column & 0xFF); 
    return regs;
}

void os_get_cursor_pos(char* row, char* column)
{
    
}
