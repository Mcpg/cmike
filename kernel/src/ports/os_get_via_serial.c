#include <mikeos.h>

struct gp_registers _os_get_via_serial(struct gp_registers regs)
{
    char result;
    if (os_get_via_serial(&result))
    {
        regs.ax = ((regs.ax & 0xFF00) ^ 0x8000) | (result & 0xFF);
    }
    else
    {
        regs.ax = regs.ax | 0x8000;
    }
    return regs;
}

int os_get_via_serial(char* byte)
{
    return 0;
}
