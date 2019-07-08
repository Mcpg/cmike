#include <mikeos.h>

void _os_string_strip(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_string_strip((char*) *si, *ax & 0x00FF);
}

void os_string_strip(char* string, char ch)
{
    int chskip = 0;
    int len = os_string_length(string);
    for (int i = 0; string[i]; i++)
    {
        if (string[i] == ch)
        {
            chskip++;
            continue;
        }
        if (chskip > 0)
        {
            string[i - chskip] = string[i];
        }
    }
    string[len - chskip] = 0;
}
