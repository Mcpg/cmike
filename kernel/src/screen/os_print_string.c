#include <mikeos.h>

/*#define OS_PRINT_STRING_DEBUG*/

void _os_print_string(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_print_string((char*) *si, 0x00);
}

/* If passed color is 0x00, no color will actually be applied,
   and the text will inherit attribute of a given text cell */
void os_print_string(char* string, char color)
{
#ifdef OS_PRINT_STRING_DEBUG
    asm volatile("int $0x16" : : "a" (0));
#endif

    for (int i = 0; string[i]; i++)
    {
        /* Check if the character is printable */
        if (string[i] >= 0 && string[i] < 32 || color == 0x00)
        {
            asm volatile("int $0x10" : : "a" (0x0E00 | string[i]));
            continue;
        }
        asm volatile("int $0x10" : : "a" (0x0900 | (unsigned char) string[i]), "b" (0x0000 | (color & 0x00FF)), "c" (1));
        asm volatile("int $0x10" : : "a" (0x0E00 | (unsigned char) string[i]));
    }
}
