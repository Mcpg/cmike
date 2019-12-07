#include <libcmike.h>

uint16_t os_bcd_to_int(uint8_t bcd)
{
    syscall_regs regs = {
        .al = bcd
    };
    cmike_syscall(OS_BCD_TO_INT_ADDR, &regs);
    return regs.ax;
}

uint32_t os_long_int_negate(uint32_t val)
{
    /*syscall_regs regs = {
        .ax = val & 0xFFFF,
        .dx = (val >> 16) & 0xFFFF
    };
    cmike_syscall(OS_LONG_INT_NEGATE, &regs);
    return (uint32_t) regs.dx << 16 | regs.ax;*/
    return -val;
}

uint16_t os_get_random(uint16_t low, uint16_t high)
{
    syscall_regs regs = {
        .ax = low,
        .bx = high
    };
    cmike_syscall(OS_GET_RANDOM_ADDR, &regs);
    return regs.cx;
}
