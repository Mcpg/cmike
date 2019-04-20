#include <mikeos.h>

struct gp_registers _os_fatal_error(struct gp_registers regs)
{
    os_fatal_error((char*) regs.ax);
    return regs;
}

void os_fatal_error(char* text)
{
    panic(text);
}
