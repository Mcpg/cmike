#include <mikeos.h>

struct gp_registers _os_port_byte_out(struct gp_registers regs)
{
    os_port_byte_out(regs.dx, regs.ax & 0x00FF);
    return regs;
}

void os_port_byte_out(int address, char byte)
{
    
}
