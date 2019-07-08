#include <mikeos.h>

void _os_get_date_string(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_get_date_string((char*) *bx);
}

void os_get_date_string(char* dest)
{
    os_string_copy("TODO ", dest);
}
