#ifndef _MIKEOS_SOUND_H
#define _MIKEOS_SOUND_H

#include <mikeos.h>

DEF_SYSCALL(void, os_speaker_tone, int frequency)
DEF_SYSCALL(void, os_speaker_off)

#endif