#include <libcmike.h>

char os_wait_for_key()
{
    syscall_regs regs = { 0 };
    cmike_syscall(OS_WAIT_FOR_KEY_ADDR, &regs);
    return regs.ax;
}

char os_check_for_key()
{
    syscall_regs regs = { 0 };
    cmike_syscall(OS_CHECK_FOR_KEY_ADDR, &regs);
    return regs.ax;
}
