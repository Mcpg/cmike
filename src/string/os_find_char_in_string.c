#include <mikeos.h>

struct gp_registers _os_find_char_in_string(struct gp_registers regs)
{
    regs.ax = os_find_char_in_string((char*) regs.si, regs.ax & 0x00FF);
    return regs;
}

int os_find_char_in_string(char* string, char ch)
{
    for (int i = 0; string[i]; i++)
    {
        if (string[i] == ch)
        {
            return i;
        }
    }
    return 0;
}
