#include <mikeos.h>

struct gp_registers _os_string_copy(struct gp_registers regs)
{
    os_string_copy((char*) regs.si, (char*) regs.di);
    return regs;
}

void os_string_copy(char* source, char* destination)
{
    for (int i = 0; source[i]; i++)
    {
        destination[i] = source[i];
    }
}
