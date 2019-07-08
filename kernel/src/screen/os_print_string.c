#include <mikeos.h>

#define SCREEN_WIDTH  80
#define SCREEN_HEIGHT 25

void _os_print_string(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_print_string((char*) *si, COLOR_CREATE(COLOR_WHITE, COLOR_BLACK, 0));
}

void os_print_string(char* string, char color)
{
    /* FIXME: implement colors in os_print_string */
    for (int i = 0; string[i]; i++)
    {
        asm("int $0x10" : : "a" (0x0E00 | string[i]));
    }
}
