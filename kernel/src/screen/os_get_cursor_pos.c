#include <mikeos.h>

void _os_get_cursor_pos(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    char row, column;
    os_get_cursor_pos(&row, &column);
    *dx = ((int) row << 8) | (column & 0xFF); 
}

void os_get_cursor_pos(char* row, char* column)
{
    int raw_pos;
    asm("int $0x10" : "=d" (raw_pos) : "a" (0x0300), "b" (0));
    *row = (raw_pos >> 8) & 0xFF;
    *column = raw_pos & 0xFF;
}
