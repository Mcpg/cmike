#include <mikeos.h>

void _os_file_selector(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    if (os_file_selector((char*) *ax))
    {
        __asm__ __volatile__("clc");
    }
    else
    {
        __asm__ __volatile__("stc");
    }
}

int os_file_selector(char* file)
{
    return 0;
}
