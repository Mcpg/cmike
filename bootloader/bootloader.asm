;
; NatLoader - CMike bootloader - adapted from one of my other projects
; It loads KERNEL.BIN from boot drive into 0x2000:0000
; The boot drive must be a floppy formatted as a FAT12
; volume
;

    bits 16
    cpu 386
    org 0x7C00

%define TARGET_SEGMENT 0x2000
%define TARGET_OFFSET  0x0000

section .text

jmp short Start
nop
OemId:             db "CMIKE   "
BytesPerSector:    dw 512
SectorsPerCluster: db 1
ReservedSectors:   dw 1
FatAmount:         db 2
DentryAmount:      dw 224 ; 14 dentry sectors to read total, 16 entries/sector
SectorAmount:      dw 2280
MediaDescriptor:   db 0xF0
SectorsPerFat:     dw 9
SectorsPerTrack:   dw 18
HeadAmount:        dw 2
HiddenSectors:     dd 0
LargeSectors:      dd 0

DriveNumber:       db 0
NtFlags:           db 0
Signature:         db 0x28
VolumeSerial:      dd 0xDEADC0DE
VolumeLabel:       db "CMike Disk "
Filesystem:        db "FAT12   "

Start:
    
    cli
        xor ax, ax
        mov ds, ax
        mov es, ax
        mov ss, ax
        mov sp, 0x7C00
        jmp 0:.Continue
        .Continue:
    sti

    cld
    mov byte [BootDrive], dl
    mov word [Fat.LoadedSector], 0xFFFF

    ; Iterate through (DentryAmount / 16) root directory sectors, each one
    ; containing 16 individual entries (512 / 32 = 16), and compare first
    ; 11 bytes (FILENAMEEXT) with KernelFilename.

    ; cx = DentryAmount / 16 = DentryAmount >> 4
    mov cx, word [DentryAmount]
    shr cx, 4

    ; ax = ReservedSectors + FatAmount * SectorsPerFat
    ; ax = current root dir sector LBA
    xor ax, ax
    mov al, byte [FatAmount]
    mul word [SectorsPerFat]
    add ax, word [ReservedSectors]

    .LookForKernel:

        push cx

        mov si, DentryBuffer
        mov bx, si
        call DiskReadSingle

        mov cx, 16
        .LookForKernel.ParseLoop:

            push si
            push cx
                mov cx, 11
                mov di, KernelFilename
                rep cmpsb
            pop cx
            pop si
            jz .LookForKernel.KernelFound

            add si, 32
            loop .LookForKernel.ParseLoop
        
        pop cx

        inc ax
        loop .LookForKernel
        jmp KernelNotFoundError

        .LookForKernel.KernelFound:
            add sp, 2

    ; ax = first cluster of KERNEL.SYS
    mov ax, word [si + 26]

    mov bx, TARGET_SEGMENT
    mov es, bx
    mov bx, TARGET_OFFSET

    .KernelLoadLoop:
        call LoadFatCluster

        jc .KernelLoaded

        add bx, 512
        jmp .KernelLoadLoop

    .KernelLoaded:
        xor dx, dx
        mov dl, byte [BootDrive]
        jmp TARGET_SEGMENT:TARGET_OFFSET

; in: ax - cluster number
;     es:bx - target buffer
; out: ax - next cluster number
;      carry flag set if the end of the file was reached,
;      cleared if there's more to read
LoadFatCluster:
    push bp
    mov bp, sp
    pusha

    ; TODO: bad cluster detection

    push ax
        push bx

            ; ax -= 2
            ; ax *= SectorsPerCluster
            ; ax += ReservedSectors + FatAmount * SectorsPerFat
            ; ax += DentryAmount >> 4

            ; ax -= 2
            sub ax, 2

            ; ax *= SectorsPerCluster
            xor bx, bx
            mov bl, byte [SectorsPerCluster]
            mul bx
            xor dx, dx ; HACK: ignoring dx

            ; ax += ReservedSectors
            add ax, word [ReservedSectors]

            ; ax += FatAmount * SectorsPerFat
            mov cx, ax
            xor ax, ax
            mov al, byte [FatAmount]
            mul word [SectorsPerFat]
            xor dx, dx ; HACK: ignoring cluster numbers > 0xFFFF, breaking EVERYTHING
            add cx, ax
            mov ax, cx

            ; ax += DentryAmount >> 4
            mov bx, word [DentryAmount]
            shr bx, 4
            add ax, bx

        pop bx

        mov cl, byte [SectorsPerCluster]
        call DiskRead

    pop ax

    mov word [.Temp], ax
    popa
    mov ax, word [.Temp]

    call GetFatEntry

    cmp ax, 0x0FF8
    jge .FileEnd

    .MoreFile:
        clc
        jmp .End

    .FileEnd:
        stc

    .End:

    leave
    ret
    .Temp: dw 0

; in: ax - entry index
; out: ax - entry value
GetFatEntry:
    push bp
    mov bp, sp
    pusha

    push es
    push 0
    pop es

    mov cx, ax

    ; ax = ax + (ax / 2)
    mov bx, ax
    shr bx, 1
    add ax, bx

    push ax
        ; ax /= 512
        shr ax, 9
        call LoadFatSector
    pop ax

    ; ax %= 512
    and ax, 511

    ; Load the raw value from FAT sector
    mov si, Fat.Data
    add si, ax
    mov ax, word [si]

    and cx, 1 ; cx contains copy of ax from beginning of the function
    jz .Even

    .Odd:
        shr ax, 4
        jmp .End
    
    .Even:
        and ax, 0x0FFF

    .End:

    mov word [.Temp], ax
    pop es
    popa
    mov ax, word [.Temp]
    leave
    ret
    .Temp: dw 0

; in: ax - fat sector
LoadFatSector:
    push bp
    mov bp, sp
    pusha

    cmp ax, word [Fat.LoadedSector]
    je .End
    mov word [Fat.LoadedSector], ax

    add ax, word [ReservedSectors]
    mov bx, Fat.Data
    mov cl, 1
    call DiskRead

    .End:
        popa
        leave
        ret

; in: ax - lba
;     cl - sector amount
;     es:bx - target buffer
; out: nothing, registers preserved
; note: ReadError will be called on read error
DiskRead:
    
    ; TODO: Reading more than one sector might not go well on some BIOSes,
    ;       if the sector block crosses a cylinder boundary.
    ;
    ;       It'd be nice to manually implement reading multiple sectors,
    ;       with multiple int 0x13 calls.

    push bp
    mov bp, sp
    pusha

    mov byte [.Temp], cl
    call LbaToChs
    mov al, byte [.Temp]

    int 0x13
    jc ReadError

    popa
    leave
    ret
    .Temp: db 0

; in: ax - lba
;     es:bx - target buffer
; It's just a front end for DiskRead
DiskReadSingle:
    push bp
    mov bp, sp
    push cx

    mov cl, 1
    call DiskRead

    pop cx
    leave
    ret

; in: ax - lba
; out: all registers required for int 0x13 read, except for al and es:bx
;
; https://wiki.osdev.org/ATA_in_x86_RealMode_(BIOS)
LbaToChs:
    push bp
    mov bp, sp

    push bx

    ; ax = temp value, bx = sector
    xor dx, dx
    div word [SectorsPerTrack]
    inc dx
    mov bx, dx

    ; ax = cylinder, dx = head
    xor dx, dx
    div word [HeadAmount]
    
    ; cl = sector | ((cylinder >> 2) & 0xC0)
    mov cl, bl
    mov bx, ax
    shr bx, 2
    and bx, 0xC0
    or cl, bl

    mov ch, al ; ch = cylinder & 0xFF
    mov dh, dl ; dh = head

    mov dl, byte [BootDrive]
    mov ah, 0x02

    pop bx

    leave
    ret

; in: si - ASCIZ string index
; out: registers preserved
PrintString:
    pusha

    .PrintLoop:
        lodsb
        cmp al, 0
        je .End

        mov ah, 0x0E
        int 0x10
        jmp .PrintLoop

    .End:
        popa
        ret

; in: si - error reason
FatalError:
    call PrintString
    jmp $

ReadError:
    mov si, ReadErrorMsg
    jmp FatalError

KernelNotFoundError:
    mov si, KernelNotFoundErrorMsg
    jmp FatalError

ReadErrorMsg: db "Read error", 0
KernelNotFoundErrorMsg: db "Kernel not found", 0
KernelFilename: db "KERNEL  BIN"

times 510 - $ + $$ db 0
dw 0xAA55

section .bss

BootDrive: resb 1

DentryBuffer: resb 512

Fat:
    .LoadedSector: resw 1
    .Data: resb 512