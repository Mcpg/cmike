#ifndef _MIKEOS_MATH_H
#define _MIKEOS_MATH_H

#include <mikeos.h>

extern unsigned int os_random_seed;

DEF_SYSCALL(unsigned int, os_bcd_to_int, unsigned char bcd)
DEF_SYSCALL(void, os_long_int_negate, int* hi, int* lo)
DEF_SYSCALL(unsigned int, os_get_random, unsigned int low, unsigned int high)
void os_seed_random();

#endif