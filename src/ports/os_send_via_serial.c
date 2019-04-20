#include <mikeos.h>

struct gp_registers _os_send_via_serial(struct gp_registers regs)
{
    if (os_send_via_serial(regs.ax & 0x00FF))
    {
        regs.ax = regs.ax ^ 0x8000;
    }
    else
    {
        regs.ax = regs.ax | 0x8000;
    }
    return regs;
}

int os_send_via_serial(char byte)
{
    return 0;
}
