#include <mikeos.h>

struct gp_registers _os_get_date_string(struct gp_registers regs)
{
    os_get_date_string((char*) regs.bx);
    return regs;
}

void os_get_date_string(char* dest)
{
    os_string_copy("TODO ", dest);
}
