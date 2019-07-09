#include <mikeos.h>

#define SCREEN_WIDTH  80
#define SCREEN_HEIGHT 25

void _os_print_string(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_print_string((char*) *si, COLOR_CREATE(COLOR_WHITE, COLOR_BLACK, 0));
}

void os_print_string(char* string, char color)
{
    char row1, col1;
    char row2, col2;

    for (int i = 0; string[i]; i++)
    {
        if (string[i] < ' ' || string[i] > '~')
        {
            asm("int $0x10" : : "a" (0x0E00 | string[i]));
            continue;
        }
        asm volatile("int $0x10" : : "a" (0x0900 | string[i]), "b" (0x0000 | color), "c" (1));
        asm volatile("int $0x10" : : "a" (0x0E00 | string[i]));
    }
}
