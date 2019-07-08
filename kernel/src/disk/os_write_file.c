#include <mikeos.h>

void _os_write_file(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    if (os_write_file((char*) *ax, (void*) *bx, *cx))
    {
        __asm__ __volatile__("clc");
    }
    else
    {
        __asm__ __volatile__("stc");
    }
}

/* Returns 0 on failure */
int os_write_file(char* filename, void* buffer, unsigned int size)
{
    return 0;
}
