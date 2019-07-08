#include <mikeos.h>

void _os_string_compare(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    if (os_string_compare((char*) *si, (char*) *di))
    {
        __asm__ __volatile__("stc");
    }
    else
    {
        __asm__ __volatile__("clc");
    }
}

int os_string_compare(char* s1, char* s2)
{
    if (os_string_length(s1) != os_string_length(s2))
        return 0;
    for (int i = 0; s1[i]; i++)
    {
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}
