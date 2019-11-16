
section .cmike_init

    global _start
    _start:

        mov word [old_stack], sp
        mov sp, stack_top

        extern main
        call main

        mov sp, word [old_stack]

        ret

    old_stack: dw 0

section .bss
    
    resb 3072
    stack_top:
