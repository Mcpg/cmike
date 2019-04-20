#ifndef _MIKEOS_MISC_H
#define _MIKEOS_MISC_H

#include <mikeos.h>

DEF_SYSCALL(char, os_get_api_version)
DEF_SYSCALL(void, os_pause, unsigned int time)
DEF_SYSCALL(void, os_fatal_error, char* text)

#endif