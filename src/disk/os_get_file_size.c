#include <mikeos.h>

char file_not_found_flag;

struct gp_registers _os_get_file_size(struct gp_registers regs)
{
    regs.bx = os_get_file_size((char*) regs.ax);
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

unsigned int os_get_file_size(char* path)
{
    return 0;
}
