    [bits 16]

section .text

global check_zf
check_zf:
    jz .yes
    xor ax, ax
    ret
    .yes:
    mov ax, 1
    ret
