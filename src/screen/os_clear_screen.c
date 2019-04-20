#include <mikeos.h>

struct gp_registers _os_clear_screen(struct gp_registers regs)
{
    os_clear_screen();
    return regs;
}

void os_clear_screen()
{
    /* Just scroll down 25 times */
    struct gp_registers regs;

    for (int i = 0; i < 25; i++)
    {

    }
}
