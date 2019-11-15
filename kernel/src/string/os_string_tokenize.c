#include <mikeos.h>

void _os_string_tokenize(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    *di = (int) os_string_tokenize(*ax & 0x00FF, (char*) *si);
}

/*
 * This function changes first occurance of character `separator` in string
 * pointed by parameter `string` and replaces it to 0. Then, it returns
 * index of the changed character + 1, or NULL if separator wasn't
 * found.
 */
char* os_string_tokenize(char separator, char* string)
{
	while (*string != 0)
	{
		if (*string == separator)
		{
			*string = 0;
			return string + 1;
		}
		string++;
	}
    return NULL;
}
