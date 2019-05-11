#include <mikeos.h>

struct gp_registers _os_serial_port_enable(struct gp_registers regs)
{
    if (os_serial_port_enable(regs.ax))
    {
        regs.ax = regs.ax ^ 0x8000;
    }
    else
    {
        regs.ax = regs.ax | 0x8000;
    }
    return regs;
}

int os_serial_port_enable(int mode)
{
    return 0;
}
