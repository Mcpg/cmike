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
