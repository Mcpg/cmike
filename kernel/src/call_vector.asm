    [bits 16]

; This macro adds another entry to system
; call vectors AND creates the assembly
; syscall handler for a method.
%macro def_call_vector 1

    section .text
        global _asm_%1:function (_asm_%1.end - _asm_%1)
        _asm_%1:

            mov word [saved_ax], ax
            mov word [saved_bx], bx
            mov word [saved_cx], cx
            mov word [saved_dx], dx
            mov word [saved_si], si
            mov word [saved_di], di

            push saved_di
            push saved_si
            push saved_dx
            push saved_cx
            push saved_bx
            push saved_ax

            extern _%1
            call _%1

            add sp, 12

            mov ax, word [saved_ax]
            mov bx, word [saved_bx]
            mov cx, word [saved_cx]
            mov dx, word [saved_dx]
            mov si, word [saved_si]
            mov di, word [saved_di]

            ret
            .end:
    
    section .call_vector
        jmp _asm_%1

%endmacro

section .bss
    saved_ax: resw 1
    saved_bx: resw 1
    saved_cx: resw 1
    saved_dx: resw 1
    saved_si: resw 1
    saved_di: resw 1

; Source: MikeOS 4.6 call vectors from /source/kernel.asm
section .call_vector
    extern _os_main
    jmp _os_main
    def_call_vector os_print_string
    def_call_vector os_move_cursor
    def_call_vector os_clear_screen
    def_call_vector os_print_horiz_line
    def_call_vector os_print_newline
    def_call_vector os_wait_for_key
    def_call_vector os_check_for_key
    def_call_vector os_int_to_string
    def_call_vector os_speaker_tone
    def_call_vector os_speaker_off
    def_call_vector os_load_file
    def_call_vector os_pause
    def_call_vector os_fatal_error
    def_call_vector os_draw_background
    def_call_vector os_string_length
    def_call_vector os_string_uppercase
    def_call_vector os_string_lowercase
    def_call_vector os_input_string
    def_call_vector os_string_copy
    def_call_vector os_dialog_box
    def_call_vector os_string_join
    def_call_vector os_get_file_list
    def_call_vector os_string_compare
    def_call_vector os_string_chomp
    def_call_vector os_string_strip
    def_call_vector os_string_truncate
    def_call_vector os_bcd_to_int
    def_call_vector os_get_time_string
    def_call_vector os_get_api_version
    def_call_vector os_file_selector
    def_call_vector os_get_date_string
    def_call_vector os_send_via_serial
    def_call_vector os_get_via_serial
    def_call_vector os_find_char_in_string
    def_call_vector os_get_cursor_pos
    def_call_vector os_print_space
    def_call_vector os_dump_string
    def_call_vector os_print_digit
    def_call_vector os_print_1hex
    def_call_vector os_print_2hex
    def_call_vector os_print_4hex
    def_call_vector os_long_int_to_string
    def_call_vector os_long_int_negate
    def_call_vector os_set_time_fmt
    def_call_vector os_set_date_fmt
    def_call_vector os_show_cursor
    def_call_vector os_hide_cursor
    def_call_vector os_dump_registers
    def_call_vector os_string_strincmp
    def_call_vector os_write_file
    def_call_vector os_file_exists
    def_call_vector os_create_file
    def_call_vector os_remove_file
    def_call_vector os_rename_file
    def_call_vector os_get_file_size
    def_call_vector os_input_dialog
    def_call_vector os_list_dialog
    def_call_vector os_string_reverse
    def_call_vector os_string_to_int
    def_call_vector os_draw_block
    def_call_vector os_get_random
    def_call_vector os_string_charchange
    def_call_vector os_serial_port_enable
    def_call_vector os_sint_to_string
    def_call_vector os_string_parse
    def_call_vector os_run_basic
    def_call_vector os_port_byte_out
    def_call_vector os_port_byte_in
    def_call_vector os_string_tokenize
