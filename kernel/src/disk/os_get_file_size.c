#include <mikeos.h>

char file_not_found_flag = 0;

void _os_get_file_size(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    *bx = os_get_file_size((char*) *ax);
    if (file_not_found_flag)
    {
        __asm__ __volatile__("stc");
    }
    else
    {
        __asm__ __volatile__("clc");
    }
}

unsigned int os_get_file_size(char* path)
{
    uint32_t file_size = cmike_get_dentry(path).file_size;
    return file_size > 0xFFFF ? 0xFFFF : file_size;
}
