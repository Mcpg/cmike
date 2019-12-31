#include <mikeos.h>

void cmike_run_program(char* path)
{
    memset(program_space, 0, 32767);
    os_load_file(path, program_space);
    
    /* TODO: command line parameter support */
    /* HACK: es should always have the value of 0x2000 */
    asm volatile(
        "push %%es\r\n"
        "push $0x2000\r\n"
        "pop %%es\r\n"
        "call 0x8000\r\n"
        "pop %%es"
        : : "a"(0),"b"(0),"c"(0),"d"(0),"S"(0),"D"(0)
    );

    os_print_newline(DEFAULT_COLOR);
}
