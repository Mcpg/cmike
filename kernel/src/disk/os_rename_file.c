#include <mikeos.h>

void _os_rename_file(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    if (os_rename_file((char*) *ax, (char*) *bx))
    {
        __asm__ __volatile__("clc");
    }
    else
    {
        __asm__ __volatile__("stc");
    }
}

int os_rename_file(char* path, char* new_name)
{
    return 0;
}
