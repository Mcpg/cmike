#include <mikeos.h>

void _os_clear_screen(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_clear_screen();
}

void os_clear_screen()
{
    os_draw_block(
    	COLOR_CREATE(COLOR_WHITE, COLOR_BLACK),
    	0, 0,
    	SCREEN_WIDTH, SCREEN_HEIGHT - 1
    );
    os_move_cursor(0, 0);
}
