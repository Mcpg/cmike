#include <libcmike.h>

uint16_t os_string_length(char* string)
{
    syscall_regs regs = {
        .ax = (uint16_t) string
    };
    cmike_syscall(OS_STRING_LENGTH_ADDR, &regs);
    return regs.ax;
}

uint16_t os_find_char_in_string(char* string, char ch)
{
    syscall_regs regs = {
        .si = (uint16_t) string,
        .al = ch
    };
    cmike_syscall(OS_FIND_CHAR_IN_STRING_ADDR, &regs);
    return regs.ax;
}

void os_string_reverse(char* string)
{
    cmike_syscall_nr(OS_STRING_REVERSE_ADDR, (syscall_regs) {
        .si = (uint16_t) string
    });
}

void os_string_charchange(char* string, char original, char replacement)
{
    cmike_syscall_nr(OS_STRING_CHARCHANGE_ADDR, (syscall_regs) {
        .si = (uint16_t) string,
        .al = original,
        .bl = replacement
    });
}

void os_string_uppercase(char* string)
{
    cmike_syscall_nr(OS_STRING_UPPERCASE_ADDR, (syscall_regs) {
        .ax = (uint16_t) string
    });
}

void os_string_lowercase(char* string)
{
    cmike_syscall_nr(OS_STRING_LOWERCASE_ADDR, (syscall_regs) {
        .ax = (uint16_t) string
    });
}

void os_string_copy(char* source, char* destination)
{
    cmike_syscall_nr(OS_STRING_COPY_ADDR, (syscall_regs) {
        .si = (uint16_t) source,
        .di = (uint16_t) destination
    });
}

void os_string_truncate(char* string, uint16_t new_size)
{
    cmike_syscall_nr(OS_STRING_TRUNCATE_ADDR, (syscall_regs) {
        .si = (uint16_t) string,
        .ax = new_size
    });
}

void os_string_join(char* s1, char* s2, char* target)
{
    cmike_syscall_nr(OS_STRING_JOIN_ADDR, (syscall_regs) {
        .ax = (uint16_t) s1,
        .bx = (uint16_t) s2,
        .cx = (uint16_t) target
    });
}

void os_string_chomp(char* string)
{
    cmike_syscall_nr(OS_STRING_CHOMP_ADDR, (syscall_regs) {
        .ax = (uint16_t) string
    });
}

void os_string_strip(char* string, char ch)
{
    cmike_syscall_nr(OS_STRING_STRIP_ADDR, (syscall_regs) {
        .si = (uint16_t) string,
        .al = ch
    });
}

bool os_string_compare(char* s1, char* s2)
{
    cmike_syscall_nr(OS_STRING_COMPARE_ADDR, (syscall_regs) {
        .si = (uint16_t) s1,
        .di = (uint16_t) s2
    });
    return last_carry_flag;
}

bool os_string_strincmp(char* s1, char* s2, uint8_t n)
{
    cmike_syscall_nr(OS_STRING_STRINCMP_ADDR, (syscall_regs) {
        .si = (uint16_t) s1,
        .di = (uint16_t) s2,
        .cl = (uint8_t) n
    });
    return last_carry_flag;
}

void os_string_parse(char* string, char** s1, char** s2, char** s3, char** s4)
{
    syscall_regs regs = {
        .si = (uint16_t) string
    };
    cmike_syscall(OS_STRING_PARSE_ADDR, &regs);

    *s1 = (char*) regs.ax;
    *s2 = (char*) regs.bx;
    *s3 = (char*) regs.cx;
    *s4 = (char*) regs.dx;
}

uint16_t os_string_to_int(char* string)
{
    syscall_regs regs = {
        .si = (uint16_t) string
    };
    cmike_syscall(OS_STRING_TO_INT_ADDR, &regs);
    return regs.ax;
}

char* os_int_to_string(uint16_t num)
{
    syscall_regs regs = {
        .ax = num
    };
    cmike_syscall(OS_INT_TO_STRING_ADDR, &regs);
    return (char*) regs.ax;
}

char* os_sint_to_string(int16_t num)
{
    syscall_regs regs = {
        .ax = (uint16_t) num
    };
    cmike_syscall(OS_SINT_TO_STRING_ADDR, &regs);
    return (char*) regs.ax;
}

char* os_long_int_to_string(uint32_t num, uint16_t base, char* target)
{
    syscall_regs regs = {
        .dx = (num >> 16) & 0xFFFF,
        .ax = num & 0xFFFF,
        .bx = base,
        .di = (uint16_t) target
    };
    cmike_syscall(OS_LONG_INT_TO_STRING_ADDR, &regs);
    return (char*) regs.di;
}

void os_set_time_fmt(uint8_t fmt)
{
    cmike_syscall_nr(OS_SET_TIME_FMT_ADDR, (syscall_regs) {
        .al = fmt
    });
}

void os_get_time_string(char* target)
{
    cmike_syscall_nr(OS_GET_TIME_STRING_ADDR, (syscall_regs) {
        .bx = (uint16_t) target
    });
}

void os_set_date_fmt(uint16_t fmt)
{
    cmike_syscall_nr(OS_SET_DATE_FMT_ADDR, (syscall_regs) {
        .ax = fmt
    });
}

void os_get_date_string(char* target)
{
    cmike_syscall_nr(OS_GET_DATE_STRING_ADDR, (syscall_regs) {
        .bx = (uint16_t) target
    });
}

char* os_string_tokenize(char separator, char* beginning)
{
    syscall_regs regs = {
        .al = separator,
        .si = (uint16_t) beginning
    };
    cmike_syscall(OS_STRING_TOKENIZE_ADDR, &regs);
    return (char*) regs.di;
}
