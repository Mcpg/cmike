#include <mikeos.h>

struct gp_registers _os_string_parse(struct gp_registers regs)
{
    os_string_parse((char*) regs.si, &regs.ax, &regs.bx, &regs.cx, &regs.dx);
    return regs;
}

void os_string_parse(char* string, int* a, int* b, int* c, int* d)
{
    char set = 0;
    int cur = 0;
    for (int i = 0; string[i]; i++)
    {
        if (string[i] == ' ')
        {
            string[i] = 0;
            switch (set)
            {
                case 0:
                    *a = cur;
                    break;
                case 1:
                    *b = cur;
                    break;
                case 2:
                    *c = cur;
                    break;
                case 3:
                    *d = cur;
                    break;
            }
            cur = i + 1;
            set++;
            if (set >= 4)
            {
                break;
            }
            continue;
        }
    }
}
