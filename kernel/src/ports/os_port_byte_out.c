#include <mikeos.h>

void _os_port_byte_out(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_port_byte_out(*dx, *ax & 0x00FF);
}

void os_port_byte_out(int address, char byte)
{
    
}
