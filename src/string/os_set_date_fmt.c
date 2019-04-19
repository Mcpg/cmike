#include <mikeos.h>

int date_format_flag = 0;

struct gp_registers _os_set_date_fmt(struct gp_registers regs)
{
    os_set_date_fmt(regs.ax);
    return regs;
}

void os_set_date_fmt(int flag)
{
    date_format_flag = flag;
}
