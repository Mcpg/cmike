#include <mikeos.h>

struct gp_registers _os_string_join(struct gp_registers regs)
{
    os_string_join((char*) regs.ax, (char*) regs.bx, (char*) regs.cx);
    return regs;
}

void os_string_join(char* s1, char* s2, char* destination)
{
    int dest_i = 0;
    for (int i = 0; s1[i]; i++)
    {
        destination[dest_i] = s1[i];
        dest_i++;
    }
    for (int i = 0; s2[i]; i++)
    {
        destination[dest_i] = s2[i];
        dest_i++;
    }
}
