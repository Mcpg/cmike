#include <mikeos.h>

void _os_sint_to_string(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    *ax = (int) os_sint_to_string((int) *ax);
}

char* os_sint_to_string(int number)
{
    static char buffer[7] = {0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 6; i++)
    {
        if (number < 0 && i == 0)
        {
            buffer[6] = '-';
            number *= -1;
        }
        buffer[i] = (number % 10) + '0';
        number /= 10;
        if (number == 0)
            break;
    }
    os_string_reverse(&buffer[0]);
    return &buffer[0];
}