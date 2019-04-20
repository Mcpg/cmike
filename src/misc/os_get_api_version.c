#include <mikeos.h>

struct gp_registers _os_get_api_version(struct gp_registers regs)
{
    regs.ax = (regs.ax & 0xFF00) | os_get_api_version();
    return regs;
}

char os_get_api_version()
{
    return MIKEOS_API_VER;
}
