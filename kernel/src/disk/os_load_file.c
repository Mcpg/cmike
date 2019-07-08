#include <mikeos.h>

void _os_load_file(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    *bx = os_load_file((char*) *ax, (void*) *cx);
    if (file_not_found_flag)
    {
        __asm__ __volatile__("stc");
    }
    else
    {
        __asm__ __volatile__("clc");
    }
}

unsigned int os_load_file(char* path, void* dest)
{
    return 0;
}
