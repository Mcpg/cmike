#include <mikeos.h>

void _os_get_file_list(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_get_file_list((char*) *ax);
}

void os_get_file_list(char* dest)
{
    int i, di;
	int dentry_sectors;
	int lba;
	int is_beginning = 1;

	ASSERT(cmike_read_boot_sector());
	dentry_sectors = boot_sector.dentry_amount * 32 / 512;
	lba = bsector_dentry_lba();

	for (i = 0; i < dentry_sectors; i++)
	{
		ASSERT(cmike_disk_read(dentry_sector, lba, 1));

		for (di = 0; di < 16; di++)
		{
			if (is_valid_filename(dentry_sector[di].filename))
			{
				if (!is_beginning)
				{
					*dest = ',';
					dest++;
				}
				dest += cmike_fat_to_path(dest, &dentry_sector[di]);
				is_beginning = 0;
			}
		}

		lba++;
	}
}
