#include <mikeos.h>

struct gp_registers _os_remove_file(struct gp_registers regs)
{
    os_remove_file((char*) regs.ax);
    return regs;
}

void os_remove_file(char* path)
{
    
}
