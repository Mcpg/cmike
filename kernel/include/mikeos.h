#ifndef _MIKEOS_H
#define _MIKEOS_H

#define MIKEOS_VER "4.6.1"
#define MIKEOS_API_VER 17

#define OS_SEGMENT 0x2000
#define OS_STACK_SIZE 1024

#include <libc.h>
#include <bios.h>

/* return type, name and its "original" parameters */
#define DEF_SYSCALL(rettype, name, ...) \
    void _##name(int* ax, int* bx, int* cx, int* dx, int* si, int* di); \
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

void os_main(uint16_t boot_device);
void panic(char* cause);
void start_cli();

extern void* os_stack_bottom;
extern void* os_stack_top;

extern void* _program_space;
#define program_space ((uint8_t*)(&_program_space))

#endif