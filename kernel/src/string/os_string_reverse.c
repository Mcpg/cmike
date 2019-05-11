#include <mikeos.h>

struct gp_registers _os_string_reverse(struct gp_registers regs)
{
    os_string_reverse((char*) regs.si);
    return regs;
}

void os_string_reverse(char* string)
{
    int len = os_string_length(string);
    char temp;
    for (int i = 0; i < len; i++)
    {
        temp = string[len - i - 1];
        string[len - i - 1] = string[i];
        string[i] = temp;
    }
}
