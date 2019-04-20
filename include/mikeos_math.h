#ifndef _MIKEOS_MATH_H
#define _MIKEOS_MATH_H

#include <mikeos.h>

DEF_SYSCALL(unsigned int, os_bcd_to_int, unsigned char bcd)
DEF_SYSCALL(void, os_long_int_negate, int* hi, int* lo)
DEF_SYSCALL(int, os_get_random, int high, int low)

#endif