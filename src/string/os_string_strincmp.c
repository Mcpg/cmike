#include <mikeos.h>

struct gp_registers _os_string_strincmp(struct gp_registers regs)
{
    if (os_string_strincmp((char*) regs.si, (char*) regs.di, regs.cx & 0x00FF))
        __asm__ __volatile__("stc");
    else
        __asm__ __volatile__("clc");
    return regs;
}

int os_string_strincmp(char* s1, char* s2, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}
