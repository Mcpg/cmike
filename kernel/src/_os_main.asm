%include "kernel.asm"

section .text

    global _os_main
    _os_main:

        ; MikeOS lives entirely within one 64k segment,
        ; so does CMike. This code sets the segment registers
        ; to 0x2000 (or whatever value is in OS_SEGMENT macro).
        cli
        mov ax, OS_SEGMENT
        mov ds, ax
        mov ss, ax
        mov sp, os_stack_top
        jmp OS_SEGMENT:.cont
        .cont:
        sti

        mov ah, 0x0E
        mov al, '!'
        ;int 0x10

        extern os_main
        push dx
        ;jmp os_main
        
        mov ah, 0x0E
        mov al, '!'
        ;int 0x10

        cli
        hlt

section .bss

    global os_stack_bottom
    global os_stack_top

    os_stack_bottom:
    resb OS_STACK_SIZE
    os_stack_top:
