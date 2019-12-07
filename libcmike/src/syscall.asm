
    bits 16
    cpu 386

section .text

    ; void cmike_syscall(uint16_t addr, syscall_regs*)
    global cmike_syscall
    cmike_syscall:
        push bp
        mov bp, sp

        pusha

        mov si, word [bp + 6]

        mov ax, word [si + 0]
        mov bx, word [si + 2]
        mov cx, word [si + 4],
        mov dx, word [si + 6],
        mov di, word [si + 10],
        mov word [temp_si], si
        mov si, word [si + 8]

        call word [bp + 4]

        pushf

        xchg si, word [temp_si]
        mov word [si + 0], ax
        mov word [si + 2], bx
        mov word [si + 4], cx
        mov word [si + 6], dx
        mov word [si + 10], di

        mov ax, word [temp_si]
        mov word [si + 8], ax

        popf

        xor al, al
        adc al, 0
        mov byte [last_carry_flag], al

        popa

        pop bp
        ret

section .bss
    
    temp_si: resw 1

    global last_carry_flag
    last_carry_flag: resb 1
