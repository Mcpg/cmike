
# Global configuration for CMike

CC = ia16-elf-gcc
AS = nasm
LD = ia16-elf-ld

CFLAGS = -nostdlib -ffreestanding \
			-mno-callee-assume-ds-data-segment \
			-Wall -Wextra -O2 -std=gnu99
ASFLAGS = -f elf
LDFLAGS =

DISK_ROOT_DIRECTORY = $(PROJECT_ROOT_DIR)/diskroot

RM = rm -f
MKDIR = mkdir -p
