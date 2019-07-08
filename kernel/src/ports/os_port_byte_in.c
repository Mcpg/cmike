#include <mikeos.h>

void _os_port_byte_in(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    *ax = (*ax & 0xFF00) | os_port_byte_in(*dx); 
}

char os_port_byte_in(int address)
{
    char retval;
    asm volatile("inb %1, %0" : "=a" (retval) : "Nd" (address));
    return retval;
}
