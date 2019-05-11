#include <mikeos.h>

struct gp_registers _os_print_space(struct gp_registers regs)
{
    os_print_space();
    return regs;
}

void os_print_space()
{
    os_print_string(" ");
}
