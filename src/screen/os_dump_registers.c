#include <mikeos.h>

struct gp_registers _os_dump_registers(struct gp_registers regs)
{
    os_dump_registers(&regs);
    return regs;
}

void os_dump_registers(struct gp_registers* regs)
{
    
}
