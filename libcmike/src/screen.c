#include <libcmike.h>

void os_print_string(char* string)
{
    cmike_syscall_nr(OS_PRINT_STRING_ADDR, (syscall_regs) {
        .si = (uint16_t) string
    });
}

void os_clear_screen()
{
    cmike_syscall_ns(OS_CLEAR_SCREEN_ADDR);
}

void os_move_cursor(uint8_t y, uint8_t x)
{
    cmike_syscall_nr(OS_MOVE_CURSOR_ADDR, (syscall_regs) {
        .dh = y,
        .dl = x
    });
}

void os_get_cursor_pos(uint8_t* target_y, uint8_t* target_x)
{
    syscall_regs regs = { 0 };
    cmike_syscall(OS_GET_CURSOR_POS_ADDR, &regs);
    *target_y = regs.dh;
    *target_x = regs.dl;
}

void os_print_horiz_line(uint8_t line_type)
{
    cmike_syscall_nr(OS_PRINT_HORIZ_LINE_ADDR, (syscall_regs) {
        .ax = line_type
    });
}

void os_show_cursor()
{
    cmike_syscall_ns(OS_SHOW_CURSOR_ADDR);
}

void os_hide_cursor()
{
    cmike_syscall_ns(OS_HIDE_CURSOR_ADDR);
}

void os_draw_block(uint8_t color, uint8_t sx, uint8_t sy, uint16_t width, uint16_t end_y)
{
    cmike_syscall_nr(OS_DRAW_BLOCK_ADDR, (syscall_regs) {
        .bl = color,
        .dl = sx,
        .dh = sy,
        .si = width,
        .di = end_y
    });
}

char* os_file_selector()
{
    syscall_regs regs = { 0 };
    cmike_syscall(OS_FILE_SELECTOR_ADDR, &regs);

    return last_carry_flag ? NULL : (char*) regs.ax;
}

uint16_t os_list_dialog(char* option_list, char* help1, char* help2)
{
    syscall_regs regs = {
        .ax = (uint16_t) option_list,
        .bx = (uint16_t) help1,
        .cx = (uint16_t) help2
    };

    cmike_syscall(OS_LIST_DIALOG_ADDR, &regs);

    return last_carry_flag ? 0 : regs.ax;
}

void os_draw_background(char* top, char* bottom, uint8_t middle_color)
{
    cmike_syscall_nr(OS_DRAW_BACKGROUND_ADDR, (syscall_regs) {
        .ax = (uint16_t) top,
        .bx = (uint16_t) bottom,
        .cx = middle_color
    });
}

void os_print_newline()
{
    cmike_syscall_ns(OS_PRINT_NEWLINE_ADDR);
}

void os_dump_registers(uint16_t ax, uint16_t bx, uint16_t cx, uint16_t dx)
{
    cmike_syscall_nr(OS_DUMP_REGISTERS_ADDR, (syscall_regs) {
        .ax = ax,
        .bx = bx,
        .cx = cx,
        .dx = dx
    });
}

void os_input_dialog(char* target, char* message)
{
    cmike_syscall_nr(OS_INPUT_DIALOG_ADDR, (syscall_regs) {
        .ax = (uint16_t) target,
        .bx = (uint16_t) message
    });
}

uint16_t os_dialog_box(char* s1, char* s2, char* s3, uint16_t mode)
{
    syscall_regs regs = {
        .ax = (uint16_t) s1,
        .bx = (uint16_t) s2,
        .cx = (uint16_t) s3,
        .dx = mode
    };

    cmike_syscall(OS_DIALOG_BOX_ADDR, &regs);

    return regs.ax;
}

void os_print_space()
{
    cmike_syscall_ns(OS_PRINT_SPACE_ADDR);
}

void os_dump_string(char* string)
{
    cmike_syscall_nr(OS_DUMP_STRING_ADDR, (syscall_regs) {
        .si = (uint16_t) string
    });
}

void os_print_digit(uint16_t digit)
{
    cmike_syscall_nr(OS_PRINT_DIGIT_ADDR, (syscall_regs) {
        .ax = digit
    });
}

void os_print_1hex(uint8_t digit)
{
    cmike_syscall_nr(OS_PRINT_1HEX_ADDR, (syscall_regs) {
        .al = digit
    });
}

void os_print_2hex(uint8_t digit)
{
    cmike_syscall_nr(OS_PRINT_2HEX_ADDR, (syscall_regs) {
        .al = digit
    });
}

void os_print_4hex(uint16_t digit)
{
    cmike_syscall_nr(OS_PRINT_4HEX_ADDR, (syscall_regs) {
        .ax = digit
    });
}

void os_input_string(char* buffer)
{
    cmike_syscall_nr(OS_INPUT_STRING_ADDR, (syscall_regs) {
        .ax = (uint16_t) buffer
    });
}
