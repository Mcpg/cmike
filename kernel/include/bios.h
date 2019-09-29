#ifndef _BIOS_H
#define _BIOS_H

/* A set of architectural utilities implemented in pure Assembly */

#define HALT() asm volatile("cli; hlt")

int check_zf();
unsigned int bios_read_system_timer();
void* get_sp();
void reboot();

#endif