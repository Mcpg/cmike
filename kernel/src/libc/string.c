#include <mikeos.h>

void* memcpy(void* dest, const void* src, int n)
{
    for (; n > 0; n--)
    {
        ((char*) dest)[n] = ((char*) src)[n];
    }
    return dest;
}

void* memset(void* dest, int val, size_t n)
{
	for (; n > 0; n--)
	{
		((char*) dest)[n] = val;
	}
	return dest;
}
