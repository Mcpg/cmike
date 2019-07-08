#include <mikeos.h>

void _os_move_cursor(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_move_cursor(*dx & 0xFF00, *dx & 0x00FF);
}

void os_move_cursor(char row, char column)
{
    
}
