#include <libcmike.h>

void os_run_basic(char* code, uint16_t size)
{
    cmike_syscall_nr(OS_RUN_BASIC_ADDR, (syscall_regs) {
        .ax = (uint16_t) code,
        .bx = size
    });
}
