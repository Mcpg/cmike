#ifndef _LIBCMIKE_H
#define _LIBCMIKE_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/* Jump table addresses */
#define OS_PRINT_STRING_ADDR 0x0003
#define OS_MOVE_CURSOR_ADDR 0x0006
#define OS_CLEAR_SCREEN_ADDR 0x0009
#define OS_PRINT_HORIZ_LINE_ADDR 0x000C
#define OS_PRINT_NEWLINE_ADDR 0x000F
#define OS_WAIT_FOR_KEY_ADDR 0x0012
#define OS_CHECK_FOR_KEY_ADDR 0x0015
#define OS_INT_TO_STRING_ADDR 0x0018
#define OS_SPEAKER_TONE_ADDR 0x001B
#define OS_SPEAKER_OFF_ADDR 0x001E
#define OS_LOAD_FILE_ADDR 0x0021
#define OS_PAUSE_ADDR 0x0024
#define OS_FATAL_ERROR_ADDR 0x0027
#define OS_DRAW_BACKGROUND_ADDR 0x002A
#define OS_STRING_LENGTH_ADDR 0x002D
#define OS_STRING_UPPERCASE_ADDR 0x0030
#define OS_STRING_LOWERCASE_ADDR 0x0033
#define OS_INPUT_STRING_ADDR 0x0036
#define OS_STRING_COPY_ADDR 0x0039
#define OS_DIALOG_BOX_ADDR 0x003C
#define OS_STRING_JOIN_ADDR 0x003F
#define OS_GET_FILE_LIST_ADDR 0x0042
#define OS_STRING_COMPARE_ADDR 0x0045
#define OS_STRING_CHOMP_ADDR 0x0048
#define OS_STRING_STRIP_ADDR 0x004B
#define OS_STRING_TRUNCATE_ADDR 0x004E
#define OS_BCD_TO_INT_ADDR 0x0051
#define OS_GET_TIME_STRING_ADDR 0x0054
#define OS_GET_API_VERSION_ADDR 0x0057
#define OS_FILE_SELECTOR_ADDR 0x005A
#define OS_GET_DATE_STRING_ADDR 0x005D
#define OS_SEND_VIA_SERIAL_ADDR 0x0060
#define OS_GET_VIA_SERIAL_ADDR 0x0063
#define OS_FIND_CHAR_IN_STRING_ADDR 0x0066
#define OS_GET_CURSOR_POS_ADDR 0x0069
#define OS_PRINT_SPACE_ADDR 0x006C
#define OS_DUMP_STRING_ADDR 0x006F
#define OS_PRINT_DIGIT_ADDR 0x0072
#define OS_PRINT_1HEX_ADDR 0x0075
#define OS_PRINT_2HEX_ADDR 0x0078
#define OS_PRINT_4HEX_ADDR 0x007B
#define OS_LONG_INT_TO_STRING_ADDR 0x007E
#define OS_LONG_INT_NEGATE_ADDR 0x0081
#define OS_SET_TIME_FMT_ADDR 0x0084
#define OS_SET_DATE_FMT_ADDR 0x0087
#define OS_SHOW_CURSOR_ADDR 0x008A
#define OS_HIDE_CURSOR_ADDR 0x008D
#define OS_DUMP_REGISTERS_ADDR 0x0090
#define OS_STRING_STRINCMP_ADDR 0x0093
#define OS_WRITE_FILE_ADDR 0x0096
#define OS_FILE_EXISTS_ADDR 0x0099
#define OS_CREATE_FILE_ADDR 0x009C
#define OS_REMOVE_FILE_ADDR 0x009F
#define OS_RENAME_FILE_ADDR 0x00A2
#define OS_GET_FILE_SIZE_ADDR 0x00A5
#define OS_INPUT_DIALOG_ADDR 0x00A8
#define OS_LIST_DIALOG_ADDR 0x00AB
#define OS_STRING_REVERSE_ADDR 0x00AE
#define OS_STRING_TO_INT_ADDR 0x00B1
#define OS_DRAW_BLOCK_ADDR 0x00B4
#define OS_GET_RANDOM_ADDR 0x00B7
#define OS_STRING_CHARCHANGE_ADDR 0x00BA
#define OS_SERIAL_PORT_ENABLE_ADDR 0x00BD
#define OS_SINT_TO_STRING_ADDR 0x00C0
#define OS_STRING_PARSE_ADDR 0x00C3
#define OS_RUN_BASIC_ADDR 0x00C6
#define OS_PORT_BYTE_OUT_ADDR 0x00C9
#define OS_PORT_BYTE_IN_ADDR 0x00CC
#define OS_STRING_TOKENIZE_ADDR 0x00CF

#define __CALL_STRING(addr) "call " #addr
#define __ASM_LBREAK "\r\n"

typedef struct
{
    union
    {
        struct
        {
            uint8_t al;
            uint8_t ah;
        };
        uint16_t ax;
    };

    union
    {
        struct
        {
            uint8_t bl;
            uint8_t bh;
        };
        uint16_t bx;
    };

    union
    {
        struct
        {
            uint8_t cl;
            uint8_t ch;
        };
        uint16_t cx;
    };

    union
    {
        struct
        {
            uint8_t dl;
            uint8_t dh;
        };
        uint16_t dx;
    };

    uint16_t si;
    uint16_t di;
} __attribute__ ((packed)) syscall_regs;

void cmike_syscall(uint16_t addr, syscall_regs*);

/* Utility method for nicer syscall syntax (for void funcs) */
void cmike_syscall_nr(uint16_t addr, syscall_regs);

#define cmike_syscall_ns(addr) \
    cmike_syscall_nr((uint16_t) (addr), (syscall_regs) {})

/* Status flags */

/*
 * Changed by cmike_syscall
 */
extern bool last_carry_flag;

/*
 * Changed by:
 *  os_load_file
 *  os_get_file_size
 */
extern bool file_not_found_flag;

/*
 * Changed by os_get_via_serial
 */
extern bool serial_read_error_flag;

/* Disk functions */
void os_get_file_list(char* target_buffer);
uint16_t os_load_file(char* filename, void* buffer);
bool os_write_file(char* filename, void* buffer, uint16_t buffer_size);
bool os_file_exists(char* filename);
void os_create_file(char* filename);
void os_remove_file(char* filename);
bool os_rename_file(char* filename, char* new_name);
uint16_t os_get_file_size(char* filename);

/* Keyboard functions */
char os_wait_for_key();
bool os_check_for_key();

/* Math functions */
uint16_t os_bcd_to_int(uint8_t bcd);
uint32_t os_long_int_negate(uint32_t val);
uint16_t os_get_random(uint16_t low, uint16_t high);

/* Misc functions */
uint8_t os_get_api_version();
void os_pause(uint16_t time); /* time in 100 ms units */
void os_fatal_error(char* message);

/* Port functions */

#define PORT_SERIAL_NORMAL_MODE 0
#define PORT_SERIAL_SLOW_MODE   1

void os_port_byte_out(uint16_t port, uint8_t data);
uint8_t os_port_byte_in(uint16_t port);
bool os_serial_port_enable(uint16_t mode);
bool os_send_via_serial(uint8_t byte);
uint8_t os_get_via_serial();

/* Screen functions */

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
        (uint8_t) ((bg << 4) | (fg & 0b00001111))

#define DEFAULT_COLOR COLOR_CREATE(COLOR_WHITE, COLOR_BLACK)

#define SCREEN_LINE_SINGLE 0
#define SCREEN_LINE_DOUBLE 1

#define DIALOG_MODE_OK        0
#define DIALOG_MODE_OK_CANCEL 1

#define DIALOG_PICKED_OK     0
#define DIALOG_PICKED_CANCEL 1

void os_print_string(char* string);
void os_clear_screen();
void os_move_cursor(uint8_t y, uint8_t x);
void os_get_cursor_pos(uint8_t* target_y, uint8_t* target_x);
void os_print_horiz_line(uint8_t line_type);
void os_show_cursor();
void os_hide_cursor();
void os_draw_block(uint8_t color, uint8_t sx, uint8_t sy, uint16_t width, uint16_t end_y);
char* os_file_selector();
uint16_t os_list_dialog(char* option_list, char* help1, char* help2);
void os_draw_background(char* top, char* bottom, uint8_t middle_color);
void os_print_newline();
void os_dump_registers(uint16_t ax, uint16_t bx, uint16_t cx, uint16_t dx);
void os_input_dialog(char* target, char* message);
uint16_t os_dialog_box(char* s1, char* s2, char* s3, uint16_t mode);
void os_print_space();
void os_dump_string(char* string);
void os_print_digit(uint16_t digit);
void os_print_1hex(uint8_t digit);
void os_print_2hex(uint8_t digit);
void os_print_4hex(uint16_t digit);
void os_input_string(char* buffer);

/* String functions */

#define TIME_FORMAT_12HR 0
#define TIME_FORMAT_24HR 1

#define DATE_FORMAT_MDY 0
#define DATE_FORMAT_DMY 1
#define DATE_FORMAT_YMD 2

#define DATE_FORMAT_MONTH_NAMES 1 << 7
#define DATE_FORMAT_SEPARATOR_CHAR 0x7F

uint16_t os_string_length(char* string);
uint16_t os_find_char_in_string(char* string, char ch);
void os_string_reverse(char* string);
void os_string_charchange(char* string, char original, char replacement);
void os_string_uppercase(char* string);
void os_string_lowercase(char* string);
void os_string_copy(char* source, char* destination);
void os_string_truncate(char* string, uint16_t new_size);
void os_string_join(char* s1, char* s2, char* target);
void os_string_chomp(char* string);
void os_string_strip(char* string, char ch);
bool os_string_compare(char* s1, char* s2);
bool os_string_strincmp(char* s1, char* s2, uint16_t n);
void os_string_parse(char* string, char** s1, char** s2, char** s3, char** s4);
uint16_t os_string_to_int(char* string);
char* os_int_to_string(uint16_t num);
char* os_sint_to_string(int16_t num);
void os_long_int_to_string(uint32_t num, uint16_t base, char* target);
void os_set_time_fmt(uint8_t fmt);
void os_get_time_string(char* target);
void os_set_date_fmt(uint8_t fmt);
void os_get_date_string(char* target);
char* os_string_tokenize(char separator, char* beginning);

/* Sound functions */
void os_speaker_tone(uint16_t tone);
void os_speaker_off();

/* BASIC functions */
void os_run_basic(char* code, uint16_t size);

/* Implemented libc functions */
void* memcpy(void* dest, void* src, uint16_t n);
void* memset(void* dest, int val, uint16_t n);

#endif