#include <mikeos.h>

struct gp_registers _os_file_selector(struct gp_registers regs)
{
    if (os_file_selector((char*) regs.ax))
    {
        __asm__ __volatile__("clc");
    }
    else
    {
        __asm__ __volatile__("stc");
    }
    return regs;
}

int os_file_selector(char* file)
{
    return 0;
}
