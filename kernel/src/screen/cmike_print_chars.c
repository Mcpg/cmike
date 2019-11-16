#include <mikeos.h>

void cmike_print_chars(char* c, int n, char color)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cmike_print_char(*c, color);
        c++;
    }
}
