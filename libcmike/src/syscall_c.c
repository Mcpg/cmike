#include <libcmike.h>

void cmike_syscall_nr(uint16_t addr, syscall_regs regs)
{
    cmike_syscall(addr, &regs);
}
