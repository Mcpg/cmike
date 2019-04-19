
SRC_DIR = src
BIN_DIR = bin
INCLUDE_DIR = include

RESULT_FILE = kernel.bin
LINKER_SCRIPT = $(SRC_DIR)/cmike.ld

CC = ia16-elf-gcc
AS = nasm
LD = ia16-elf-ld

CFLAGS = -nostdlib -ffreestanding -I$(INCLUDE_DIR) \
			-mno-callee-assume-ds-data-segment \
			-Wall -Wextra -O2 -std=gnu99
ASFLAGS = -f elf
LDFLAGS =

RM = rm -f
MKDIR = mkdir -p
