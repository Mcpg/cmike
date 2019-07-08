#include <mikeos.h>

void _os_string_length(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    *ax = os_string_length((char*) *ax);
}

int os_string_length(char* string)
{
    int len;
    for (len = 0; string[len]; len++) ;
    return len;
}
