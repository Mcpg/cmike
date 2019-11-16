#include <libcmike.h>

bool file_not_found_flag = false;

void os_get_file_list(char* target_buffer)
{
    asm volatile(
        __CALL_STRING(OS_GET_FILE_LIST_ADDR)
            : : "a" (target_buffer)
    );
}

uint16_t os_load_file(char* filename, void* buffer)
{
    uint16_t retval = 0;

    asm volatile(

        __CALL_STRING(OS_LOAD_FILE_ADDR) __ASM_LBREAK

        "jc .not_found0 " __ASM_LBREAK
        "mov $1, %%ax   " __ASM_LBREAK
        ".not_found0:   " __ASM_LBREAK

        : "=a" (file_not_found_flag), "=b" (retval)
        : "a" (filename), "c" (buffer)

    );

    return retval;
}

bool os_write_file(char* filename, void* buffer, uint16_t buffer_size)
{
    bool retval = false;

    asm volatile(

        __CALL_STRING(OS_WRITE_FILE_ADDR) __ASM_LBREAK

        "jc .failure   " __ASM_LBREAK
        "mov $1, %%ax  " __ASM_LBREAK
        ".failure:     " __ASM_LBREAK

        : "=a" (retval)
        : "a" (filename), "b" (buffer), "c" (buffer_size)

    );

    return retval;
}

bool os_file_exists(char* filename)
{
    bool retval = false;

    asm volatile(

        __CALL_STRING(OS_FILE_EXISTS_ADDR) __ASM_LBREAK

        "jc .not_found1 " __ASM_LBREAK
        "mov $1, %%ax   " __ASM_LBREAK
        ".not_found1:   " __ASM_LBREAK

        : "=a" (retval)
        : "a" (filename)

    );

    return retval;
}

void os_create_file(char* filename)
{
    asm volatile(

        __CALL_STRING(OS_CREATE_FILE_ADDR)

        :
        : "a" (filename)
    );
}

void os_remove_file(char* filename)
{
    asm volatile(

        __CALL_STRING(OS_REMOVE_FILE_ADDR)

        :
        : "a" (filename)
    );
}

bool os_rename_file(char* filename, char* new_name)
{
    bool retval = false;

    asm volatile(

        __CALL_STRING(OS_RENAME_FILE_ADDR) __ASM_LBREAK

        "jc .error    " __ASM_LBREAK
        "mov $1, %%ax " __ASM_LBREAK
        ".error:      " __ASM_LBREAK

        :
        : "a" (filename), "b" (new_name)

    );

    return retval;
}

uint16_t os_get_file_size(char* filename)
{
    uint16_t retval = 0;

    asm volatile(

        __CALL_STRING(OS_GET_FILE_SIZE_ADDR) __ASM_LBREAK

        "jc .not_found2 " __ASM_LBREAK
        "mov $1, %%ax   " __ASM_LBREAK
        ".not_found2:   " __ASM_LBREAK

        : "=a" (file_not_found_flag), "=b" (retval)
        : "a" (filename)

    );

    return retval;
}
