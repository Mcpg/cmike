#include <mikeos.h>

struct gp_registers _os_create_file(struct gp_registers regs)
{
    os_create_file((char*) regs.ax);
    return regs;
}

void os_create_file(char* path)
{
    
}
