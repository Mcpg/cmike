#include <mikeos.h>

struct gp_registers _os_write_file(struct gp_registers regs)
{
    if (os_write_file((char*) regs.ax, (void*) regs.bx, regs.cx))
    {
        __asm__ __volatile__("clc");
    }
    else
    {
        __asm__ __volatile__("stc");
    }
    return regs;
}

/* Returns 0 on failure */
int os_write_file(char* filename, void* buffer, unsigned int size)
{
    return 0;
}
