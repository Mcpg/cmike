#ifndef _MIKEOS_DISK_H
#define _MIKEOS_DISK_H

#include <mikeos.h>

extern char boot_device;
extern int sectors_per_track;
extern int disk_heads;

extern char file_not_found_flag;

extern char last_disk_error;

void cmike_disk_init(char bootdev);
char cmike_disk_write(void* dst, int lba, char sector_amount);
char cmike_disk_read(void* dst, int lba, char sector_amount);

DEF_SYSCALL(void, os_get_file_list, char* dest)
DEF_SYSCALL(unsigned int, os_load_file, char* dest, void* buffer)
DEF_SYSCALL(int, os_write_file, char* filename, void* buffer, unsigned int size)
DEF_SYSCALL(int, os_file_exists, char* path)
DEF_SYSCALL(void, os_create_file, char* path)
DEF_SYSCALL(void, os_remove_file, char* path)
DEF_SYSCALL(int, os_rename_file, char* path, char* new_name)
DEF_SYSCALL(unsigned int, os_get_file_size, char* path)

#endif