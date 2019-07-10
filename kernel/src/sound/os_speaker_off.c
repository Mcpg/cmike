#include <mikeos.h>

void _os_speaker_off(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_speaker_off();
}

void os_speaker_off()
{
    os_port_byte_out(0x61, os_port_byte_in(0x61) & 0xFC);
}
