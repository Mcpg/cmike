#ifndef _BIOS_H
#define _BIOS_H

/* A set of architectural utilities implemented in pure Assembly */

#define HALT() asm volatile("cli; hlt")

int check_zf();
unsigned int bios_read_system_timer();
void* get_sp();
void reboot();
uint16_t bios_read_disk(
	uint16_t sectors_n, /* al */
	uint16_t cyl_sec,   /* cx */
	uint16_t head,      /* dh */ 
	uint16_t drive,     /* dl */
	void* dest          /* bx */
	                    /* es = ds */
);

#endif