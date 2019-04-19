section .text

%macro int_func_template 1
    mov word [temp_sp], sp
    pop sp
    mov word [temp_sp2], sp
    popa
    int %1
    mov sp, word [temp_sp2]
    pusha
    mov sp, word [temp_sp]
    push sp
    mov sp, word [temp_sp]
%endmacro

global int10h
int10h:
    int_func_template 0x10
    ret

global int13h
int13h:
    int_func_template 0x13
    ret

global int16h
int16h:
    int_func_template 0x16
    ret

global check_zf
check_zf:
    jz .yes
    xor ax, ax
    ret
    .yes:
    mov ax, 1
    ret

section .bss
    temp_sp: resw 1
    temp_sp2: resw 1