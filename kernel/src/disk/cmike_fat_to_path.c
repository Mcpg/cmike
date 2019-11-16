#include <mikeos.h>

int cmike_fat_to_path(char* destination, struct dir_entry* dentry)
{
    char filename[9] = { 0 };
    char extension[4] = { 0 };
    int filename_size;
    int extension_size;
    int string_end;

    ASSERT(dentry);

    memcpy(filename, dentry->filename, 8);
    memcpy(extension, dentry->extension, 3);

    string_end = os_find_char_in_string(filename, ' ');
    filename_size = (string_end == 0) ? 8 : string_end;

    string_end = os_find_char_in_string(extension, ' ');
    extension_size = (string_end == 0) ? 3 : string_end;

    memcpy(destination, filename, filename_size);
    memcpy(destination + filename_size + 1, extension, extension_size);
    destination[filename_size] = '.';

    return filename_size + 1 + extension_size;
}
