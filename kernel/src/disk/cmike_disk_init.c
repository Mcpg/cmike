#include <mikeos.h>

char boot_device = 0;
int sectors_per_track = 0;
int disk_heads = 0;

char last_disk_error = 0;

/* https://wiki.osdev.org/ATA_in_x86_RealMode_(BIOS) */
void cmike_disk_init(char bootdev)
{
    boot_device = bootdev;

    /* It might be better to just predict the values if the boot device is a floppy */
    if (bootdev == 0x00)
    {
        sectors_per_track = 18;
        disk_heads = 2;
    }
    else
    {
        /* Get the disk geometry from the BIOS */
        asm("int $0x13" : "=c" (sectors_per_track), "=d" (disk_heads) : "a" (0x0800), "d" (bootdev & 0xFF));
        sectors_per_track &= 0x3F;
        disk_heads = (disk_heads >> 8) + 1;
    }

    ASSERT(cmike_read_boot_sector());
}
