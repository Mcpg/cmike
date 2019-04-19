#include <mikeos.h>

void panic(char* text)
{
    /*TODO: implementation*/
    while (1)
        __asm__ __volatile__("cli; hlt");
}