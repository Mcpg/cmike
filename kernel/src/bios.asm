    [bits 16]

section .text

global check_zf
check_zf:
    xor ax, ax
    jz .yes
    ret
    .yes:
    inc ax
    ret

global bios_read_system_timer
bios_read_system_timer:
    ; Read a word from 0000:046C
    push es
    
    xor ax, ax
    mov es, ax
    
    mov ax, word [es:0x046C]

    pop es
    ret

global get_sp
get_sp:
    mov ax, sp
    add ax, 2 ; Remove callstack
    ret

global reboot
reboot:
    mov ax, 0x40
    mov es, ax
    mov word [es:0x72], 0x1234
    jmp 0xFFFF:0000
