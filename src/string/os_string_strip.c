#include <mikeos.h>

struct gp_registers _os_string_strip(struct gp_registers regs)
{
    os_string_strip((char*) regs.si, regs.ax & 0x00FF);
    return regs;
}

void os_string_strip(char* string, char ch)
{
    int chskip = 0;
    int len = os_string_length(string);
    for (int i = 0; string[i]; i++)
    {
        if (string[i] == ch)
        {
            chskip++;
            continue;
        }
        if (chskip > 0)
        {
            string[i - chskip] = string[i];
        }
    }
    string[len - chskip] = 0;
}
