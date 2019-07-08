#include <mikeos.h>

char time_format_flag = 0;

void _os_set_time_fmt(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_set_time_fmt(*ax & 0x00FF);
}

void os_set_time_fmt(char flag)
{
    if (flag != TIME_FORMAT_12HR 
        && flag != TIME_FORMAT_24HR)
    {
        /* TODO: change to just shutting down the program, probably
                 (throwing a kernel panic because of time format
                 is not the wisest idea)*/
        panic("Incorrect time format");
    }

    time_format_flag = flag;
}
