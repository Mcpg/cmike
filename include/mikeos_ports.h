#ifndef _MIKEOS_PORTS_H
#define _MIKEOS_PORTS_H

#include <mikeos.h>

#define PORT_SERIAL_NORMAL_MODE 0
#define PORT_SERIAL_SLOW_MODE   1

DEF_SYSCALL(void, os_port_byte_out, int address, char byte)
DEF_SYSCALL(char, os_port_byte_in, int address)
DEF_SYSCALL(int,  os_serial_port_enable, int mode)
DEF_SYSCALL(int,  os_send_via_serial, char byte)
DEF_SYSCALL(int,  os_get_via_serial, char* byte)

#endif