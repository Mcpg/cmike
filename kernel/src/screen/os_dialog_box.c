#include <mikeos.h>

void _os_dialog_box(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    *ax = os_dialog_box((char*) *ax, (char*) *bx, (char*) *cx, *dx);
}

int os_dialog_box(char* string1, char* string2, char* string3, int mode)
{
    return 0;
}
