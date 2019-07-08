#include <mikeos.h>

void _os_string_tokenize(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    *di = os_string_tokenize(*ax & 0x00FF, (char*) *si);
}

int os_string_tokenize(char separator, char* beginning)
{
    return 0;
}
