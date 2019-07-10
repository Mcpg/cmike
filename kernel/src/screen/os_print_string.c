#include <mikeos.h>

#define SCREEN_WIDTH  80
#define SCREEN_HEIGHT 25

void _os_print_string(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_print_string((char*) *si, DEFAULT_COLOR);
}

void os_print_string(char* string, char color)
{
    for (int i = 0; string[i]; i++)
    {
        /* Check if the character is printable */
        if (string[i] >= 0 && string[i] < 32)
        {
            asm volatile("int $0x10" : : "a" (0x0E00 | string[i]));
            continue;
        }
        asm volatile("int $0x10" : : "a" (0x0900 | (unsigned char) string[i]), "b" (0x0000 | (color & 0x00FF)), "c" (1));
        asm volatile("int $0x10" : : "a" (0x0E00 | (unsigned char) string[i]));
    }
}
