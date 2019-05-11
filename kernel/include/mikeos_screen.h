#ifndef _MIKEOS_SCREEN_H
#define _MIKEOS_SCREEN_H

#include <mikeos.h>

#define SCREEN_LINE_SINGLE 0
#define SCREEN_LINE_DOUBLE 1

DEF_SYSCALL(void, os_print_string, char* string)
DEF_SYSCALL(void, os_clear_screen)
DEF_SYSCALL(void, os_move_cursor, char row, char column)
DEF_SYSCALL(void, os_get_cursor_pos, char* row, char* column)
DEF_SYSCALL(void, os_print_horiz_line, int line_type)
DEF_SYSCALL(void, os_show_cursor)
DEF_SYSCALL(void, os_hide_cursor)
DEF_SYSCALL(void, os_draw_block, char color, char start_x, char start_y, char width, char end_y)
DEF_SYSCALL(int,  os_file_selector, char* result)
DEF_SYSCALL(int,  os_list_dialog, char* strings, char* help1, char* help2)
DEF_SYSCALL(void, os_draw_background, char* top, char* bottom, int color)
DEF_SYSCALL(void, print_newline)
DEF_SYSCALL(void, os_dump_registers)
DEF_SYSCALL(void, os_input_dialog, char* message, char* buffer)
DEF_SYSCALL(int,  os_dialog_box, char* string1, char* string2, char* string3, int mode)
DEF_SYSCALL(void, os_print_space)
DEF_SYSCALL(void, os_dump_string, char* string)
DEF_SYSCALL(void, os_print_digit, int digit)
DEF_SYSCALL(void, os_print_1hex, char number)
DEF_SYSCALL(void, os_print_2hex, char number)
DEF_SYSCALL(void, os_print_4hex, int number)
DEF_SYSCALL(void, os_input_string, char* buffer)

#endif