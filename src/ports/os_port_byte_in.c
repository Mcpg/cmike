#include <mikeos.h>

struct gp_registers _os_port_byte_in(struct gp_registers regs)
{
    regs.ax = (regs.ax & 0xFF00) | os_port_byte_in(regs.dx); 
    return regs;
}

char os_port_byte_in(int address)
{
    return 0;
}
