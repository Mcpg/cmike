#include <mikeos.h>

struct gp_registers _os_string_tokenize(struct gp_registers regs)
{
    regs.di = os_string_tokenize(regs.ax & 0x00FF, (char*) regs.si);
    return regs;
}

int os_string_tokenize(char separator, char* beginning)
{
    return 0;
}
