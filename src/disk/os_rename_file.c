#include <mikeos.h>

struct gp_registers _os_rename_file(struct gp_registers regs)
{
    if (os_rename_file((char*) regs.ax, (char*) regs.bx))
    {
        __asm__ __volatile__("clc");
    }
    else
    {
        __asm__ __volatile__("stc");
    }
    return regs;
}

int os_rename_file(char* path, char* new_name)
{
    return 0;
}
