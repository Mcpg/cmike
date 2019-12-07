#include <libcmike.h>

bool serial_read_error_flag = false;

void os_port_byte_out(uint16_t port, uint8_t data)
{
    cmike_syscall_nr(OS_PORT_BYTE_OUT_ADDR, (syscall_regs) {
        .dx = port,
        .al = data
    });
}

uint8_t os_port_byte_in(uint16_t port)
{
    syscall_regs regs = {
        .dx = port
    };
    cmike_syscall(OS_PORT_BYTE_IN_ADDR, &regs);
    return regs.al;
}

bool os_serial_port_enable(uint16_t mode)
{
    syscall_regs regs = {
        .ax = mode
    };
    cmike_syscall(OS_SERIAL_PORT_ENABLE_ADDR, &regs);
    return (regs.ah & 0x80) == 0;
}

bool os_send_via_serial(uint8_t byte)
{
    syscall_regs regs = {
        .al = byte
    };
    cmike_syscall(OS_SEND_VIA_SERIAL_ADDR, &regs);
    return (regs.ah & 0x80) == 0;
}

uint8_t os_get_via_serial()
{
    syscall_regs regs = { 0 };
    cmike_syscall(OS_GET_VIA_SERIAL_ADDR, &regs);
    serial_read_error_flag = (regs.ah & 0x80) != 0;
    return serial_read_error_flag ? 0 : regs.al;
}
