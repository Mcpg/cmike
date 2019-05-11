#include <mikeos.h>

char time_format_flag = 0;

struct gp_registers _os_set_time_fmt(struct gp_registers regs)
{
    os_set_time_fmt(regs.ax & 0x00FF);
    return regs;
}

void os_set_time_fmt(char flag)
{
    if (flag != TIME_FORMAT_12HR 
        && flag != TIME_FORMAT_24HR)
    {
        /* TODO: change to just shutting down the program, probably
                 (throwing a kernel panic because of time format
                 is not the wisest idea)*/
        panic("Incorrect time format");
    }

    time_format_flag = flag;
}
