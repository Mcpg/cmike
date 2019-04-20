#include <mikeos.h>

struct gp_registers _os_bcd_to_int(struct gp_registers regs)
{
    regs.ax = os_bcd_to_int(regs.ax & 0x00FF);
    return regs;
}

unsigned int os_bcd_to_int(unsigned char bcd)
{
    return 0;
}
