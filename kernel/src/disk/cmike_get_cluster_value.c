#include <mikeos.h>

uint8_t fat_buffer[512] = { 0 };

/* https://wiki.osdev.org/FAT#FAT_12_2 */
uint16_t cmike_get_cluster_value(uint16_t cluster)
{
    uint16_t fat_offset = cluster + (cluster / 2);
    uint16_t table_value;

    /* TODO: Won't there be an edge case when 2 FAT sectors will need to be loaded
       (when fat_offset == 511, somehow)? */
    ASSERT(cmike_disk_read(fat_buffer, bsector_fat0_lba() + (fat_offset / 512), 1) == 1);

    table_value = fat_buffer[fat_offset % 512] | (fat_buffer[fat_offset % 512 + 1] << 8);

    return ((cluster & 1) ? (table_value >> 4) : table_value) & 0x0FFF;
}
