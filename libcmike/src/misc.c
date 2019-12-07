#include <libcmike.h>

uint8_t os_get_api_version()
{
    syscall_regs regs = { 0 };
    cmike_syscall(OS_GET_API_VERSION_ADDR, &regs);
    return regs.al;
}

void os_pause(uint16_t time)
{
    cmike_syscall_nr(OS_PAUSE_ADDR, (syscall_regs) {
        .ax = time
    });
}

void os_fatal_error(char* message)
{
    cmike_syscall_nr(OS_FATAL_ERROR_ADDR, (syscall_regs) {
        .ax = (uint16_t) message
    });
}
