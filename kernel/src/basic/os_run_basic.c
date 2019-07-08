#include <mikeos.h>

void _os_run_basic(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_run_basic((char*) *ax, *bx);
}

void os_run_basic(char* code, int size)
{
    /* TODO */
}
