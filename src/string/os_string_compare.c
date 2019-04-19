#include <mikeos.h>

struct gp_registers _os_string_compare(struct gp_registers regs)
{
    if (os_string_compare((char*) regs.si, (char*) regs.di))
    {
        __asm__ __volatile__("stc");
    }
    else
    {
        __asm__ __volatile__("clc");
    }
    return regs;
}

int os_string_compare(char* s1, char* s2)
{
    if (os_string_length(s1) != os_string_length(s2))
        return 0;
    for (int i = 0; s1[i]; i++)
    {
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}
