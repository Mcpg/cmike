#include <mikeos.h>

void _os_file_selector(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    *ax = (int) os_file_selector();

    if ((*ax) != 0)
    {
        __asm__ __volatile__("clc");
    }
    else
    {
        __asm__ __volatile__("stc");
    }
}

char* os_file_selector()
{
    static char filename[12] = { 0 };

    char buffer[1024] = { 0 };
    os_get_file_list(buffer);

    int option = os_list_dialog(buffer, "Pick a file, or press [Esc] key", "_");

    if (option == 0)
        return NULL;

    memset(filename, 0, sizeof(filename));

    option--;

    /* Find beginning of selected option in the buffer... */
    char* current = buffer;
    while (option > 0)
    {
        if (*current == ',')
            option--;
        current++;
    }

    /* ...and then copy it to filename buffer */
    char* current_filename = filename;
    while (*current != ',' && *current != 0)
    {
        *current_filename = *current;
        current++;
        current_filename++;
    }
    *current_filename = 0;

    return filename;
}
