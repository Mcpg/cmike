#include <mikeos.h>

void _os_clear_screen(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_clear_screen();
}

void os_clear_screen()
{
    /* Reset the video mode */
    asm("int $0x10" : : "a" (0x0003));
    
    /* BIOS service: enable "bright" colors and disable blinking */
    asm("int $0x10" : : "a" (0x1003), "b" (0x0000));
}
