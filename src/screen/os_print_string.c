#include <mikeos.h>

struct gp_registers _os_print_string(struct gp_registers regs)
{
    os_print_string((char*) regs.si);
    return regs;
}

void os_print_string(char* string)
{
    /* Potentially I could implement manual text buffer manipulation,
       which could possibly increase the performance */

    struct gp_registers regs;
    regs.ax = 0x0E00; /* ah = 0x0E */

    for (int i = 0; string[i]; i++)
    {
        regs.ax = 0x0E00 | (string[i] & 0xFF);
        int10h(&regs);
    }
}
