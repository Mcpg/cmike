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

void _os_int_to_string(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    *ax = (int) os_int_to_string((unsigned int) *ax);
}

char* os_int_to_string(unsigned int number)
{
    static char buffer[6] = {0, 0, 0, 0, 0, 0};
    int i;

    for (i = 0; i < 5; i++)
    {
        buffer[i] = (number % 10) + '0';
        number /= 10;
        if (number == 0)
        {
            i++;
            break;
        }
    }

    buffer[i] = 0;
    os_string_reverse(buffer);

    return buffer;
}
