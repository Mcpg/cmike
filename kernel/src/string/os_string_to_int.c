#include <mikeos.h>

static inline int pow(int base, int power)
{
    if (power == 0)
        return 1;
    for (power--; power > 0; power--)
    {
        base *= base; 
    }
    return base;
}

void _os_string_to_int(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    *ax = os_string_to_int((char*) *si);
}

unsigned int os_string_to_int(char* string)
{
    int result = 0;
    int length = os_string_length(string);
    for (int i = 0; i < length; i++)
    {
        result += (string[i] - '0') * pow(10, length - i - 1);
    }
    return result;
}
