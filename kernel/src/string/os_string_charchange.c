#include <mikeos.h>

struct gp_registers _os_string_charchange(struct gp_registers regs)
{
    os_string_charchange((char*) regs.si, regs.ax & 0x00FF, regs.bx & 0x00FF);
    return regs;
}

void os_string_charchange(char* string, char original, char replacement)
{
    for (int i = 0; string[i]; i++)
    {
        if (string[i] == original)
        {
            string[i] = replacement;
        }
    }
}
