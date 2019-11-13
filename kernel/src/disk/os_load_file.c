#include <mikeos.h>

void _os_load_file(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    *bx = os_load_file((char*) *ax, (uint8_t*) *cx);
    if (file_not_found_flag)
    {
        __asm__ __volatile__("stc");
    }
    else
    {
        __asm__ __volatile__("clc");
    }
}

unsigned int os_load_file(char* path, uint8_t* dest)
{
    uint16_t current_cluster;
    struct dir_entry dentry = cmike_get_dentry(path);
    if (file_not_found_flag || dentry.file_size > 0xFFFF)
        return 0;
    
    ASSERT(cmike_read_boot_sector());

    current_cluster = dentry.first_cluster;
    while (current_cluster < 0xFF7)
    {
        
        //os_print_string("\r\n---- reading cluster: ", DEFAULT_COLOR);
        //os_print_4hex(current_cluster, DEFAULT_COLOR);
        //asm("int $0x16" : : "a" (0));

        ASSERT(cmike_disk_read(
            dest,
            current_cluster + bsector_data_lba() - 2,
            1
        ) == 1);        
        current_cluster = cmike_get_cluster_value(current_cluster);
        dest += 512;
    }

    return dentry.file_size;
}
