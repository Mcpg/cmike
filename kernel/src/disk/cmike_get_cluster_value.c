#include <mikeos.h>

uint8_t fat_buffer[512] = { 0 };

/* https://wiki.osdev.org/FAT#FAT_12_2 */
uint16_t cmike_get_cluster_value(uint16_t cluster)
{
	int fat_offset = cluster + (cluster / 2);
	int table_value;

	ASSERT(cmike_disk_read(fat_buffer, bsector_fat0_lba() + (fat_offset / 512), 1) == 1);

	table_value = fat_buffer[fat_offset % 512];
	return (cluster & 1) ? table_value >> 4 : table_value & 0x0FFF;
}
