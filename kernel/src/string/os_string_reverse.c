#include <mikeos.h>

void _os_string_reverse(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_string_reverse((char*) *si);
}

void os_string_reverse(char* string)
{
    int len = os_string_length(string);
    char temp;
    for (int i = 0; i < len; i++)
    {
        temp = string[len - i - 1];
        string[len - i - 1] = string[i];
        string[i] = temp;
    }
}
