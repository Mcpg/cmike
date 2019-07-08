#include <mikeos.h>

int date_format_flag = 0;

void _os_set_date_fmt(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_set_date_fmt(*ax);
}

void os_set_date_fmt(int flag)
{
    date_format_flag = flag;
}
