#include <mikeos.h>

struct gp_registers _os_load_file(struct gp_registers regs)
{
    regs.bx = os_load_file((char*) regs.ax, (void*) regs.cx);
    if (file_not_found_flag)
    {
        __asm__ __volatile__("stc");
    }
    else
    {
        __asm__ __volatile__("clc");
    }
    return regs;
}

unsigned int os_load_file(char* path, void* dest)
{
    return 0;
}
