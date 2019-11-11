#include <mikeos.h>

void _os_file_exists(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    if (os_file_exists((char*) *ax))
    {
        __asm__ __volatile__("clc");
    }
    else
    {
        __asm__ __volatile__("stc");
    }
}

int os_file_exists(char* path)
{
	cmike_get_dentry(path);
    return file_not_found_flag == 0;
}
