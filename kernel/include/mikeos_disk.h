#ifndef _MIKEOS_DISK_H
#define _MIKEOS_DISK_H

#include <mikeos.h>

extern char boot_device;
extern int sectors_per_track;
extern int disk_heads;

extern char file_not_found_flag;

/* Last disk error returned by int 0x13 functions */
extern char last_disk_error;

#define FAT_OEMID_SIZE 8
#define FAT_VOLUME_LABEL_SIZE 11
#define FAT_FS_ID_SIZE 8
struct _boot_sector
{
	/* BIOS Parameter Block */
	uint8_t jmp[3];
	char oem_id[FAT_OEMID_SIZE];
	uint16_t bytes_per_sector;
	uint8_t sectors_per_cluster;
	uint16_t reserved_sectors;
	uint8_t fat_amount;
	uint16_t dentry_amount;
	uint16_t small_sectors;
	uint8_t media_descriptor_type;
	uint16_t sectors_per_fat;
	uint16_t sectors_pet_track;
	uint16_t head_amount;
	uint32_t hidden_sectors;
	uint32_t large_sectors;

	/* Extended Boot Record */
	uint8_t drive_number;
	uint8_t nt_reserved;
	uint8_t signature;
	uint32_t volume_id;
	char volume_label[FAT_VOLUME_LABEL_SIZE];
	char filesystem_id[FAT_FS_ID_SIZE];

	/* Misc. */
	uint8_t boot_code[448];
	uint16_t bootable_signature;
} __attribute__((packed));
extern struct _boot_sector boot_sector;

inline int bsector_fat0_lba()
{
	return boot_sector.reserved_sectors;
}

inline int bsector_dentry_lba()
{
	return bsector_fat0_lba() + (boot_sector.fat_amount * boot_sector.sectors_per_fat);
}

inline int bsector_data_lba()
{
	return bsector_dentry_lba() + (boot_sector.dentry_amount * 32 / 512);
}

struct fat_time
{
	uint16_t hour : 5;
	uint16_t minutes : 6;
	uint16_t seconds : 5;
} __attribute__((packed));

struct fat_date
{
	uint16_t year : 7;
	uint16_t month : 4;
	uint16_t day : 5;
} __attribute__((packed));

#define FILE_READ_ONLY 0x01
#define FILE_HIDDEN    0x02
#define FILE_SYSTEM    0x04
#define FILE_VOLUME_ID 0x08
#define FILE_DIRECTORY 0x10
#define FILE_ARCHIVE   0x20
#define FILE_LFN       0x0F

struct dir_entry
{
	char filename[8];
	char extension[3];

	uint8_t attributes;
	uint8_t nt_reserved;

	uint8_t creation_seconds;
	struct fat_time creation_time;
	struct fat_date creation_date;
	struct fat_date last_access_date;
	uint16_t reserved;
	struct fat_time last_modification_time;
	struct fat_date last_modification_date;
	uint16_t first_cluster;
	uint32_t file_size;
} __attribute__((packed));

/* 512 B */
extern struct dir_entry dentry_sector[16];

inline int is_valid_filename(char* filename)
{
	return *filename != 0x0 && *filename != 0x05 && *filename != 0x2E && *filename != 0xE5;
}

void cmike_disk_init(char bootdev);
char cmike_disk_write(void* dst, int lba, char sector_amount);
char cmike_disk_read(void* dst, int lba, char sector_amount);

int cmike_read_boot_sector();

/* Returns length of generated string */
int cmike_fat_to_path(char* destination, struct dir_entry* dentry);
uint16_t cmike_get_cluster_value(uint16_t fat_index);

/* If the file is not found, file_not_found_flag is set,
   and a zeroed structure is returned. */
struct dir_entry cmike_get_dentry(char* name);

DEF_SYSCALL(void, os_get_file_list, char* dest)
DEF_SYSCALL(unsigned int, os_load_file, char* dest, uint8_t* buffer)
DEF_SYSCALL(int, os_write_file, char* filename, void* buffer, unsigned int size)
DEF_SYSCALL(int, os_file_exists, char* path)
DEF_SYSCALL(void, os_create_file, char* path)
DEF_SYSCALL(void, os_remove_file, char* path)
DEF_SYSCALL(int, os_rename_file, char* path, char* new_name)
DEF_SYSCALL(unsigned int, os_get_file_size, char* path)

#endif