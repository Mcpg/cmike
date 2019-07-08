#include <mikeos.h>

void _os_bcd_to_int(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    *ax = os_bcd_to_int(*ax & 0x00FF);
}

unsigned int os_bcd_to_int(unsigned char bcd)
{
    return ((bcd >> 4) & 0x0F) * 10 + (bcd & 0xF);
}
