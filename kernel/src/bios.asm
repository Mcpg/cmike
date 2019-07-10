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