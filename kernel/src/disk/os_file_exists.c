#include <mikeos.h>

struct gp_registers _os_file_exists(struct gp_registers regs)
{
    if (os_file_exists((char*) regs.ax))
    {
        __asm__ __volatile__("clc");
    }
    else
    {
        __asm__ __volatile__("stc");
    }
    return regs;
}

int os_file_exists(char* path)
{
    return 0;
}
