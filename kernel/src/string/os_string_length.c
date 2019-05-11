#include <mikeos.h>

struct gp_registers _os_string_length(struct gp_registers regs)
{
    regs.ax = os_string_length((char*) regs.ax);
    return regs;
}

int os_string_length(char* string)
{
    int len;
    for (len = 0; string[len]; len++) ;
    return len;
}
