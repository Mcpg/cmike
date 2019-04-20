#include <mikeos.h>

struct gp_registers _os_input_dialog(struct gp_registers regs)
{
    os_input_dialog((char*) regs.bx, (char*) regs.ax);
    return regs;
}

void os_input_dialog(char* message, char* target)
{
    
}
