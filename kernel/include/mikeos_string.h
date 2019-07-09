#ifndef _MIKEOS_STRING_H
#define _MIKEOS_STRING_H

#include <mikeos.h>

#define TIME_FORMAT_12HR 0
#define TIME_FORMAT_24HR 1

#define DATE_FORMAT_MDY 0
#define DATE_FORMAT_DMY 1
#define DATE_FORMAT_YMD 2

#define DATE_FORMAT_MONTH_NAMES 1 << 7
#define DATE_FORMAT_SEPARATOR_CHAR 0x7F /*(?)*/

extern char time_format_flag;
extern int  date_format_flag;

DEF_SYSCALL(int,   os_string_length, char* string)
DEF_SYSCALL(int,   os_find_char_in_string, char* string, char ch)
DEF_SYSCALL(void,  os_string_reverse, char* string)
DEF_SYSCALL(void,  os_string_charchange, char* string, char ch, char replacement)
DEF_SYSCALL(void,  os_string_uppercase, char* string)
DEF_SYSCALL(void,  os_string_lowercase, char* string)
DEF_SYSCALL(void,  os_string_copy, char* source, char* destination)
DEF_SYSCALL(void,  os_string_truncate, char* source, int n)
DEF_SYSCALL(void,  os_string_join, char* s1, char* s2, char* dest)
DEF_SYSCALL(void,  os_string_chomp, char* string)
DEF_SYSCALL(void,  os_string_strip, char* string, char ch)
DEF_SYSCALL(int,   os_string_compare, char* s1, char* s2)
DEF_SYSCALL(void,  os_string_parse, char* string, int* a, int* b, int* c, int* d)
DEF_SYSCALL(unsigned int, os_string_to_int, char* string)
DEF_SYSCALL(char*, os_int_to_string, unsigned int number)
DEF_SYSCALL(char*, os_sint_to_string, int number)
DEF_SYSCALL(void,  os_long_int_to_string, int hi, int lo, int base, char* destination)
DEF_SYSCALL(void,  os_set_time_fmt, char flag)
DEF_SYSCALL(void,  os_get_time_string, char* dest)
DEF_SYSCALL(void,  os_set_date_fmt, int flag)
DEF_SYSCALL(void,  os_get_date_string, char* dest)
DEF_SYSCALL(int,   os_string_tokenize, char separator, char* beginning)

void cmike_print_char(char c, char color);

#endif