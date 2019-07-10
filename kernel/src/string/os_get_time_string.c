#include <mikeos.h>

void _os_get_time_string(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_get_time_string((char*) *bx);
}

void os_get_time_string(char* dest)
{
    int tmp;
    char hour, minute;

    asm("int $0x1A" : "=c" (tmp) : "a" (0x0200));
    
    hour = os_bcd_to_int((tmp >> 8) & 0xFF);
    minute = os_bcd_to_int(tmp & 0xFF);

    if (time_format_flag == TIME_FORMAT_24HR)
    {
        /* Example: 0101 hours -> 10 characters */
        dest[10] = 0;
        dest[4] = ' '; /* Separator between hour and the word "hours" */
        if (hour < 10)
        {
            dest[0] = '0';
        }
        else
        {
            dest[0] = digits[(hour / 10) % 10];
        }

        dest[1] = digits[hour % 10];    
        if (minute < 10)
        {
            dest[2] = '0';
        }
        else
        {
            dest[2] = digits[(minute / 10) % 10];    
        }
        dest[3] = digits[minute % 10];

        os_string_copy("hours", dest + 5);
    }
    else
    {
        /* Example: 11:20 AM -> 8 characters */
        dest[9] = 0;
        dest[2] = ':';
        dest[5] = ' ';

        dest[7] = 'M';

        if (hour < 13) /* AM */
        {
            dest[6] = 'A';
        }
        else /* PM */
        {
            dest[6] = 'P';
            hour -= 12;
        }

        if (hour < 10)
        {
            dest[0] = '0';
        }
        else
        {
            dest[0] = digits[(hour / 10) % 10];
        }
        dest[1] = digits[hour % 10];

        if (minute < 10)
        {
            dest[3] = '0';
        }
        else
        {
            dest[3] = digits[(minute / 10) % 10];
        }
        dest[4] = digits[minute % 10];
    }
}
