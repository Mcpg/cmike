#ifndef _MIKEOS_SCREEN_H
#define _MIKEOS_SCREEN_H

#include <mikeos.h>

#define COLOR_BLACK         0x0
#define COLOR_BLUE          0x1
#define COLOR_GREEN         0x2
#define COLOR_CYAN          0x3
#define COLOR_RED           0x4
#define COLOR_MAGENTA       0x5
#define COLOR_BROWN         0x6
#define COLOR_LIGHT_GRAY    0x7
#define COLOR_DARK_GRAY     0x8
#define COLOR_LIGHT_BLUE    0x9
#define COLOR_LIGHT_GREEN   0xA
#define COLOR_LIGHT_CYAN    0xB
#define COLOR_LIGHT_RED     0xC
#define COLOR_LIGHT_MAGENTA 0xD
#define COLOR_YELLOW        0xE
#define COLOR_WHITE         0xF

#define COLOR_CREATE(fg, bg) \
        (char) ((bg << 4) | (fg & 0b00001111))

#define DEFAULT_COLOR COLOR_CREATE(COLOR_WHITE, COLOR_BLACK)

#define SCREEN_LINE_SINGLE 0
#define SCREEN_LINE_DOUBLE 1

#define DIALOG_MODE_OK        0
#define DIALOG_MODE_OK_CANCEL 1

extern char* digits;

DEF_SYSCALL(void, os_print_string, char* string, char color)
DEF_SYSCALL(void, os_clear_screen)
DEF_SYSCALL(void, os_move_cursor, char row, char column)
DEF_SYSCALL(void, os_get_cursor_pos, char* row, char* column)
DEF_SYSCALL(void, os_print_horiz_line, int line_type, char color)
DEF_SYSCALL(void, os_show_cursor)
DEF_SYSCALL(void, os_hide_cursor)
DEF_SYSCALL(void, os_draw_block, char color, char start_x, char start_y, char width, char end_y)
DEF_SYSCALL(int,  os_file_selector, char* result)
DEF_SYSCALL(int,  os_list_dialog, char* strings, char* help1, char* help2)
DEF_SYSCALL(void, os_draw_background, char* top, char* bottom, int color)
DEF_SYSCALL(void, os_print_newline, char color)
DEF_SYSCALL(void, os_dump_registers, int* ax, int* bx, int* cx, int* dx, int* si, int *di, char color)
DEF_SYSCALL(void, os_input_dialog, char* message, char* buffer)
DEF_SYSCALL(int,  os_dialog_box, char* string1, char* string2, char* string3, int mode)
DEF_SYSCALL(void, os_print_space, char color)
DEF_SYSCALL(void, os_dump_string, char* string, char color)
DEF_SYSCALL(void, os_print_digit, int digit, char color)
DEF_SYSCALL(void, os_print_1hex, char number, char color)
DEF_SYSCALL(void, os_print_2hex, char number, char color)
DEF_SYSCALL(void, os_print_4hex, int number, char color)
DEF_SYSCALL(void, os_input_string, char* buffer, char displayed_color, int max_size)

void cmike_print_char(char c, char color);
void cmike_print_dec(int number, char color);
void cmike_print_chars(char* c, int n, char color);

#endif