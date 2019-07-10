#include <mikeos.h>

void _os_speaker_tone(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_speaker_tone(*ax);
}

void os_speaker_tone(int frequency)
{
    os_port_byte_out(0x43, 0xB6);
    os_port_byte_out(0x42, frequency & 0x00FF);
    os_port_byte_out(0x42, (frequency >> 8) & 0x00FF);
    os_port_byte_out(0x61, (os_port_byte_in(0x61) | 0x03) & 0xFF);
}
