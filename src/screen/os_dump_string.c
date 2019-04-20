#include <mikeos.h>

struct gp_registers _os_dump_string(struct gp_registers regs)
{
    os_dump_string((char*) regs.si);
    return regs;
}

void os_dump_string(char* string)
{
    
}
