#ifndef _LIBC_H
#define _LIBC_H

#include <stddef.h>
#include <stdarg.h>
#include <stdint.h>

void* memcpy(void* dest, const void* src, int n);
void* memset(void* dest, int val, size_t n);

#endif