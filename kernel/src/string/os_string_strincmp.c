#include <mikeos.h>

void _os_string_strincmp(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    if (os_string_strincmp((char*) *si, (char*) *di, *cx & 0x00FF))
        __asm__ __volatile__("stc");
    else
        __asm__ __volatile__("clc");
}

int os_string_strincmp(char* s1, char* s2, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}
