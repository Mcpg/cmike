#include <mikeos.h>

void _os_string_join(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_string_join((char*) *ax, (char*) *bx, (char*) *cx);
}

void os_string_join(char* s1, char* s2, char* destination)
{
    int dest_i = 0;
    for (int i = 0; s1[i]; i++)
    {
        destination[dest_i] = s1[i];
        dest_i++;
    }
    for (int i = 0; s2[i]; i++)
    {
        destination[dest_i] = s2[i];
        dest_i++;
    }
}
