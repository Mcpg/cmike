
# Global configuration for CMike

CC = ia16-elf-gcc
AS = nasm
LD = ia16-elf-ld
AR = ia16-elf-ar

# Note:
# The flags disable unused-parameter warning,
# because every syscall handler will have
# unused parameters - that's an expected behavior.
CFLAGS = -nostdlib -ffreestanding \
			-mno-callee-assume-ds-data-segment \
			-Wall -Wextra -Werror -O2 -std=gnu99 \
			-Wno-unused-parameter -funsigned-char
ASFLAGS = -f elf
LDFLAGS =
LDLIBS = -L$(dir $(shell $(CC) --print-libgcc-file-name)) -lgcc
ARFLAGS =

DISK_ROOT_DIRECTORY = $(PROJECT_ROOT_DIR)/diskroot

RM = rm -f
MKDIR = mkdir -p
