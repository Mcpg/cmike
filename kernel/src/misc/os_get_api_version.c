#include <mikeos.h>

void _os_get_api_version(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    *ax = (*ax & 0xFF00) | os_get_api_version();
}

char os_get_api_version()
{
    return MIKEOS_API_VER;
}
