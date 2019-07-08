#include <mikeos.h>

void _os_pause(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_pause(*ax);
}

void os_pause(unsigned int time)
{
    
}
