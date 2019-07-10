#ifndef _MIKEOS_KEYBOARD_H
#define _MIKEOS_KEYBOARD_H

#include <mikeos.h>

extern char last_scancode;

DEF_SYSCALL(char, os_wait_for_key)
DEF_SYSCALL(char, os_check_for_key)

#endif