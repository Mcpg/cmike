#ifndef _LIBC_H
#define _LIBC_H

#include <stddef.h>
#include <stdarg.h>
#include <stdint.h>

inline int min(int a, int b)
{
	return a < b ? a : b;
}

inline int max(int a, int b)
{
	return a > b ? a : b;
}

inline char toupper(char c)
{
	return (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
}

void* memcpy(void* dest, const void* src, int n);
void* memset(void* dest, int val, size_t n);
int memcmp(void* a, void* b, int n);

#endif