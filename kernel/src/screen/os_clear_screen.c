#include <mikeos.h>

void _os_clear_screen(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_clear_screen();
}

void os_clear_screen()
{
    /* Just scroll down 100 times */
    for (int i = 0; i < 100; i++)
    {
        os_print_string("\n");
    }
    os_move_cursor(0, 0);
}
