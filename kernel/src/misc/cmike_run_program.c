#include <mikeos.h>

void cmike_run_program(char* path)
{
    memset(program_space, 0, 32767);
    os_load_file(path, program_space);
    
    /* TODO: command line parameter support */
    asm volatile("call 0x8000" : : "a"(0),"b"(0),"c"(0),"d"(0),"S"(0),"D"(0));

    os_print_newline(DEFAULT_COLOR);
}
