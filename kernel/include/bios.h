#ifndef _BIOS_H
#define _BIOS_H

/* A set of architectural utilities implemented in pure Assembly */

#include <stdint.h>

/* General purpose registers pushed by `pusha` */
struct gp_registers
{
    unsigned int di;
    unsigned int si;
    unsigned int bp;
    unsigned int sp;
    unsigned int bx;
    unsigned int dx;
    unsigned int cx;
    unsigned int ax;
};

void int10h(struct gp_registers* regs);
void int13h(struct gp_registers* regs);
void int16h(struct gp_registers* regs);

int check_zf();

#endif