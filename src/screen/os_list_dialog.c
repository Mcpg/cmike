#include <mikeos.h>

struct gp_registers _os_list_dialog(struct gp_registers regs)
{
    int result = os_list_dialog((char*) regs.ax, (char*) regs.bx, (char*) regs.cx);
    if (result)
    {
        __asm__ __volatile__("clc");
    }
    else
    {
        __asm__ __volatile__("stc");
    }
    regs.ax = result;
    return regs;
}

int os_list_dialog(char* strings, char* help1, char* help2)
{
    return 0;
}
