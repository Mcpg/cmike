#include <mikeos.h>

struct gp_registers _os_string_truncate(struct gp_registers regs)
{
    os_string_truncate((char*) regs.si, regs.ax);
    return regs;
}

void os_string_truncate(char* string, int n)
{
    string[n] = 0;
}
