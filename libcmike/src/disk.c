#include <libcmike.h>

bool file_not_found_flag = false;

void os_get_file_list(char* target_buffer)
{
    cmike_syscall_nr(OS_GET_FILE_LIST_ADDR, (syscall_regs) {
        .ax = (uint16_t) target_buffer
    });
}

uint16_t os_load_file(char* filename, void* buffer)
{
    syscall_regs regs = {
        .ax = (uint16_t) filename,
        .cx = (uint16_t) buffer
    };
    cmike_syscall(OS_LOAD_FILE_ADDR, &regs);

    file_not_found_flag = last_carry_flag;

    return regs.bx;
}

bool os_write_file(char* filename, void* buffer, uint16_t buffer_size)
{
    cmike_syscall_nr(OS_WRITE_FILE_ADDR, (syscall_regs) {
        .ax = (uint16_t) filename,
        .bx = (uint16_t) buffer,
        .cx = buffer_size
    });

    return last_carry_flag;
}

bool os_file_exists(char* filename)
{
    cmike_syscall_nr(OS_FILE_EXISTS_ADDR, (syscall_regs) {
        .ax = (uint16_t) filename
    });

    return last_carry_flag;
}

void os_create_file(char* filename)
{
    cmike_syscall_nr(OS_CREATE_FILE_ADDR, (syscall_regs) {
        .ax = (uint16_t) filename
    });
}

void os_remove_file(char* filename)
{
    cmike_syscall_nr(OS_REMOVE_FILE_ADDR, (syscall_regs) {
        .ax = (uint16_t) filename
    });
}

bool os_rename_file(char* filename, char* new_name)
{
    cmike_syscall_nr(OS_CREATE_FILE_ADDR, (syscall_regs) {
        .ax = (uint16_t) filename,
        .bx = (uint16_t) new_name
    });
    return last_carry_flag;
}

uint16_t os_get_file_size(char* filename)
{
    syscall_regs regs = {
        .ax = (uint16_t) filename
    };

    cmike_syscall(OS_GET_FILE_SIZE_ADDR, &regs);

    file_not_found_flag = last_carry_flag;
    return regs.bx;
}
