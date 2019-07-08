    [bits 16]

; Whenever GCC decides to put embed some of its
; functions in the kernel, you can implement
; them here.

section .text

; unsigned int __udivsi3 (unsigned int a, unsigned int b)
global __udivsi3
__udivsi3:
    push si
    push dx
    xor dx, dx

    mov si, sp
    mov ax, word [si + 2]
    div word [si + 4]
    
    pop dx
    pop si
    ret

; unsigned int __umodsi3 (unsigned int a, unsigned int b)
global __umodsi3
__umodsi3:
    push si
    push dx
    xor dx, dx

    mov si, sp
    mov ax, word [si + 2]
    div word [si + 4]
    mov ax, dx
    
    pop dx
    pop si
    ret