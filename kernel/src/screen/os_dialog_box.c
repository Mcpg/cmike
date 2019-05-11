#include <mikeos.h>

struct gp_registers _os_dialog_box(struct gp_registers regs)
{
    regs.ax = os_dialog_box((char*) regs.ax, (char*) regs.bx, (char*) regs.cx, regs.dx);
    return regs;
}

int os_dialog_box(char* string1, char* string2, char* string3, int mode)
{
    return 0;
}
