#include <mikeos.h>

void _os_list_dialog(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    int result = os_list_dialog((char*) *ax, (char*) *bx, (char*) *cx);
    if (result)
    {
        __asm__ __volatile__("clc");
    }
    else
    {
        __asm__ __volatile__("stc");
    }
    *ax = result;
}

int os_list_dialog(char* strings, char* help1, char* help2)
{
    return 0;
}
