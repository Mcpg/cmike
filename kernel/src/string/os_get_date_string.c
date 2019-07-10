#include <mikeos.h>

void _os_get_date_string(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_get_date_string((char*) *bx);
}

void os_get_date_string(char* dest)
{
    char century, year, month, day;
    int tmp1, tmp2;

    asm("int $0x1A" : "=c" (tmp1), "=d" (tmp2) : "a" (0x0400));
    century = os_bcd_to_int((tmp1 >> 8) & 0xFF);
    year = os_bcd_to_int(tmp1 & 0xFF);
    month = os_bcd_to_int((tmp2 >> 8) & 0xFF);
    day = os_bcd_to_int(tmp2 & 0xFF);

    dest[10] = 0;

    switch (date_format_flag)
    {
        case DATE_FORMAT_DMY:
            dest[0] = digits[(day / 10) % 10];
            dest[1] = digits[day % 10];
            dest[2] = '/';
            dest[3] = digits[(month / 10) % 10];
            dest[4] = digits[month % 10];
            dest[5] = '/';
            dest[6] = digits[(century / 10) % 10];
            dest[7] = digits[century % 10];
            dest[8] = digits[(year / 10) % 10];
            dest[9] = digits[year % 10];
            break;
        case DATE_FORMAT_MDY:
            dest[0] = digits[(month / 10) % 10];
            dest[1] = digits[month % 10];
            dest[2] = '/';
            dest[3] = digits[(day / 10) % 10];
            dest[4] = digits[day % 10];
            dest[5] = '/';
            dest[6] = digits[(century / 10) % 10];
            dest[7] = digits[century % 10];
            dest[8] = digits[(year / 10) % 10];
            dest[9] = digits[year % 10];
            break;
        default: /* YMD */
            dest[0] = digits[(century / 10) % 10];
            dest[1] = digits[century % 10];
            dest[2] = digits[(year / 10) % 10];
            dest[3] = digits[year % 10];
            dest[4] = '/';
            dest[5] = digits[(month / 10) % 10];
            dest[6] = digits[month % 10];
            dest[7] = '/';
            dest[8] = digits[(day / 10) % 10];
            dest[9] = digits[day % 10];
            break;
    }
}
