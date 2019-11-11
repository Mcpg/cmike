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

global bios_read_disk
bios_read_disk:
    push bp
    mov bp, sp

    push bx
    push cx
    push dx
    push es

    ; Sectors N
    mov ax, word [bp + 4]

    ; Cylinder, sector
    mov cx, word [bp + 6]

    ; Head
    mov bx, word [bp + 8]
    mov dh, bl

    ; Drive
    mov bx, word [bp + 10]
    mov dl, bl

    ; Destination
    mov bx, word [bp + 12]
    push ds
    pop es

    mov ah, 0x02
    int 0x13

    pop es
    pop dx
    pop cx
    pop bx

    pop bp
    ret
