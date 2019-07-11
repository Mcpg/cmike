#include <mikeos.h>

char cmike_disk_read(void* dst, int lba, char sector_amount)
{
    int cylinder, sector, head;

    sector = (lba % sectors_per_track) + 1;
    head = (lba / sectors_per_track) % disk_heads;
    cylinder = (lba / sectors_per_track) / disk_heads;

    int result;
    /* FIXME: make the es setting code better and less dependant on the OS segment default value of 0x2000 */
    asm("push %%es; push %%ax; mov $0x2000, %%ax; mov %%ax, %%es; pop %%ax; int $0x13; pop %%es; cli;hlt"
        : "=a" (result)
        : "a" (0x0200 | (sector_amount & 0xFF)),
          "b" ((unsigned int) dst),
          "c" (((cylinder & 0xFF) << 8) | ((cylinder >> 2) & 0xC0) | (sector & 0x3F)),
          "d" (((head & 0xFF) << 8) | (boot_device & 0xFF))
    );

    last_disk_error = (result >> 8) & 0xFF;
    return result & 0xFF;
}
