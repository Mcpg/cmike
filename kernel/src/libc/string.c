#include <mikeos.h>

void* memcpy(void* dest, const void* src, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        ((char*) dest)[i] = ((char*) src)[i];
    }
    return dest;
}

void* memset(void* dest, int val, size_t n)
{
    unsigned int i;
    for (i = 0; i < n; i++)
    {
        ((char*) dest)[i] = val;
    }
    return dest;
}

int memcmp(void* a, void* b, int n)
{
    int i;
    char va, vb;

    for (i = 0; i < n; i++)
    {
        va = ((char*) a)[i];
        vb = ((char*) b)[i];

        if (va < vb)
            return -1;
        if (va > vb)
            return 1;
    }

    return 0;
}
