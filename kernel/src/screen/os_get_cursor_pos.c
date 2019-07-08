#include <mikeos.h>

void _os_get_cursor_pos(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    char row, column;
    os_get_cursor_pos(&row, &column);
    *dx = ((int) row << 8) | (column & 0xFF); 
}

void os_get_cursor_pos(char* row, char* column)
{
    
}
