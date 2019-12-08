    
    bits 16
    cpu 386
    org 0x0000

; CMike experimental FAT12 bootloader
; Filesystem dependant variables are hardcoded.
; Not the best design, but ¯\_(ツ)_/¯

section .text

jmp short _start

oem_id:              db "CMIKELDR"
bytes_per_sector:    dw 512
sectors_per_cluster: db 1
reserved_sectors:    dw 1
fat_amount:          db 2
dentry_amount:       dw 224 ; 14 dentry sectors to read total, 16 entries per sector
sector_amount:       dw 2280
media_descriptor:    db 0xF0
sectors_per_fat:     dw 9
sectors_per_track:   dw 18
head_amount:         dw 2
hidden_sectors:      dd 0
large_sectors:       dd 0

drive_number:        db 0
nt_flags:            db 0
signature:           db 0x28
volume_serial:       db 0xDEADC0DE
volume_label:        db "CMIKE DISK "
filesystem:          db "FAT12   "

_start:
    
    cli
    
    mov ax, 0x3000
    mov ss, ax
    mov sp, 0xFFFF

    mov ax, 0x07C0
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    jmp 0x07C0:.cont
    .cont:

    sti
    cld

    mov byte [boot_drive], dl

    ; Start reading dentries to find the kernel
    mov cx, 14 ; 14 sectors
    mov ax, 19 ; dentries start at LBA 19
    .sector_loop:
        pusha

        call lba2chs
        mov al, 1
        mov bx, sector_temp
        int 0x13
        jc read_error

        mov cx, 16 ; 16 dentries per sector
        mov si, sector_temp
        .dentry_loop:

            push cx
            push si

            mov di, kernel_filename
            mov cx, 11

            ;

            loop .dentry_loop


        popa
        loop .sector_loop

    ; ax - initial cluster index
    .found_dentry:

    jmp $

read_error:
    mov si, read_error_msg
    call print_string
    .die_loop:
        cli
        hlt
        jmp .die_loop

kernel_not_found:
    mov si, kernel_not_found_msg
    call print_string
    .die_loop:
        cli
        hlt
        jmp .die_loop

; si - string
print_string:
    push si
    push ax

    .check_loop:
        lodsb
        cmp al, 0
        je .end
        mov ah, 0x0E
        int 0x10
        jmp .check_loop

    .end:

    pop ax
    pop si
    ret

; ax - LBA
; outputs values ready for int 0x13 (ah, ch, cl, dh, dl, es:bx and al remaining to set)
lba2chs:
    push bx

    xor dx, dx
    mov bx, 18
    div bx
    inc dx
    mov byte [.sector], dl

    xor dx, dx
    mov bx, 2
    div bx

    mov cx, ax
    mov ch, cl

    mov bx, ax
    shr bx, 2
    and bx, 0xC0

    mov cl, byte [.sector]
    or cl, bl

    mov dh, dl

    mov dl, byte [boot_drive]

    pop bx

    mov ah, 0x02
    ret

    .sector: db 0

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

jmp $

boot_drive: db 0
kernel_filename: db "KERNEL  BIN"

kernel_not_found_msg: db "[!] KERNEL.BIN not found", 0
read_error_msg: db "[!] Read error", 0

    times 510 - ($ - $$) nop
    dw 0xAA55

section .bss

sector_temp: resb 512
