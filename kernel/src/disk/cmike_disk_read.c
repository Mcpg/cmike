#include <mikeos.h>

char cmike_disk_read(void* dst, int lba, char sector_amount)
{
    int cylinder, sector, head;

    sector = (lba % sectors_per_track) + 1;
    head = (lba / sectors_per_track) % disk_heads;
    cylinder = (lba / sectors_per_track) / disk_heads;

    int result = bios_read_disk(
        sector_amount,
        (uint16_t) ((cylinder << 8) | (sector & 0xFF) | ((cylinder >> 2) & 0xC0)),
        head, boot_device,
        dst
    );

    last_disk_error = (result >> 8) & 0xFF;
    return result & 0xFF;
}
