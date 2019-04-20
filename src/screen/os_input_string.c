#include <mikeos.h>

struct gp_registers _os_input_string(struct gp_registers regs)
{
    os_input_string((char*) regs.ax);
    return regs;
}

void os_input_string(char* buffer)
{
    
}
