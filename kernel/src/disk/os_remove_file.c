#include <mikeos.h>

void _os_remove_file(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_remove_file((char*) *ax);
}

void os_remove_file(char* path)
{
    
}
