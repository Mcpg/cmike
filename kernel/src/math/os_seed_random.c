#include <mikeos.h>

int os_random_seed;

void os_seed_random()
{
    os_random_seed = 0;

    os_port_byte_out(0x70, 0x02);
    os_random_seed |= os_port_byte_in(0x71) << 8; /* Put current minute in the high byte */
    os_port_byte_out(0x70, 0x00);
    os_random_seed |= os_port_byte_in(0x71) & 0xFF; /* Put current second in the low byte */
}
