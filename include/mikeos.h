#ifndef _MIKEOS_H
#define _MIKEOS_H

#include <bios.h>

/* return type, name and its "original" parameters */
#define DEF_SYSCALL(rettype, name, ...) \
    struct gp_registers _##name(struct gp_registers regs); \
    rettype name(__VA_ARGS__);

#include <mikeos_keyboard.h>
#include <mikeos_string.h>

void panic(char* text);
void os_main();

extern void* kernel_disk_buffer;
extern void* program_space;

#endif