#include <mikeos.h>

struct gp_registers _os_string_uppercase(struct gp_registers regs)
{
    os_string_uppercase((char*) regs.ax);
    return regs;
}

void os_string_uppercase(char* string)
{
    for (int i = 0; string[i]; i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] -= 32;
        }
    }
}
