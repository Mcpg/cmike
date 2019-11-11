#include <mikeos.h>

/* 16*32 = 512B */
struct dir_entry dentry_sector[16] = { 0 };

/* returns 1 if equal, 0 if not */
static int compare_name_fat_internal(char* name, struct dir_entry* internal)
{
	int filename_size;
	int extension_size;
	char* extension_string;
	char converted_string[12];
	memset(converted_string, ' ', 11);
	converted_string[11] = 0;

	ASSERT(os_string_length(name) <= 12);
	ASSERT(os_string_length(name) != 0);

	filename_size = os_find_char_in_string(name, '.');
	if (filename_size == 0)
	{
		filename_size = os_string_length(name);
		extension_size = 0;
		extension_string = NULL;
	}
	else
	{
		extension_size = os_string_length(name) - filename_size - 1;
		extension_string = name + filename_size + 1;
	}

	memcpy(converted_string, name, filename_size);
	memcpy(converted_string + 8, extension_string, extension_size);
	os_string_uppercase(converted_string);

	return memcmp(converted_string, internal->filename, 11) == 0;
}

struct dir_entry cmike_get_dentry(char* name)
{
	int i, di;
	int dentry_sectors;
	int lba;
	struct dir_entry empty = { 0 };

	ASSERT(cmike_read_boot_sector());
	dentry_sectors = boot_sector.dentry_amount * 32 / 512;
	lba = bsector_dentry_lba();

	for (i = 0; i < dentry_sectors; i++)
	{
		ASSERT(cmike_disk_read(dentry_sector, lba, 1));

		for (di = 0; di < 16; di++)
		{
			if (compare_name_fat_internal(name, &dentry_sector[di]))
			{
				file_not_found_flag = 0;
				return dentry_sector[di];
			}
		}

		lba++;
	}

	file_not_found_flag = 1;
	return empty;
}
