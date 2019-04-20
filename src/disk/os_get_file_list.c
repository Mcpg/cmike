#include <mikeos.h>

struct gp_registers _os_get_file_list(struct gp_registers regs)
{
    os_get_file_list((char*) regs.ax);
    return regs;
}

void os_get_file_list(char* dest)
{
    os_string_copy("Unimplemented", dest);
}
