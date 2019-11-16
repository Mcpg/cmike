#include <mikeos.h>

void cmike_run_program(char* path)
{
    memset(program_space, 0, 32767);
    os_load_file(path, program_space);
    ((void (*)()) program_space)();
    os_print_newline(DEFAULT_COLOR);
}
