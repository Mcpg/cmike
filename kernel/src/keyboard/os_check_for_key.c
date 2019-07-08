#include <mikeos.h>

void _os_check_for_key(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    *ax = os_check_for_key();
}

char os_check_for_key()
{
    asm volatile("int $0x16" : : "a" (0x0100)); /* ah = 0x01 */

    if (check_zf())
    {
        /* No key has been pressed */
        return '\0';
    }
    else
    {
        /* Remove the key from the buffer */
        return os_wait_for_key();
    }
}
