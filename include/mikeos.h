#ifndef _MIKEOS_H
#define _MIKEOS_H

#define MIKEOS_VER "4.6.1"
#define MIKEOS_API_VER 17

#include <bios.h>

/* return type, name and its "original" parameters */
#define DEF_SYSCALL(rettype, name, ...) \
    struct gp_registers _##name(struct gp_registers regs); \
    rettype name(__VA_ARGS__);

#include <mikeos_disk.h>
#include <mikeos_keyboard.h>
#include <mikeos_math.h>
#include <mikeos_misc.h>
#include <mikeos_ports.h>
#include <mikeos_screen.h>
#include <mikeos_string.h>
#include <mikeos_sound.h>
#include <mikeos_basic.h>

void panic(char* text);
void os_main();

extern void* kernel_disk_buffer;
extern void* program_space;

#endif