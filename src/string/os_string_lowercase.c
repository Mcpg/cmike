#include <mikeos.h>

struct gp_registers _os_string_lowercase(struct gp_registers regs)
{
    os_string_lowercase((char*) regs.ax);
    return regs;
}

void os_string_lowercase(char* string)
{
    for (int i = 0; string[i]; i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] += 32;
        }
    }
}
