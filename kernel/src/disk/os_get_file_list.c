#include <mikeos.h>

void _os_get_file_list(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_get_file_list((char*) *ax);
}

void os_get_file_list(char* dest)
{
    os_string_copy("Unimplemented", dest);
}
