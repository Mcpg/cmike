
# Global configuration for CMike

VERSION = 0.1.0

CC = ia16-elf-gcc
AS = nasm
LD = $(CC)
AR = ia16-elf-ar

MCOPY = mcopy
DD = dd

# Note:
# The flags disable unused-parameter warning,
# because every syscall handler will have
# unused parameters - that's an expected behavior.
CFLAGS = -nostdlib -ffreestanding \
			-mno-callee-assume-ds-data-segment \
			-Wall -Wextra -Werror -O2 -std=gnu99 \
			-Wno-unused-parameter -funsigned-char \
			-mcmodel=tiny

# Apply optimizations for the 286, since ia16-elf toolchain
# doesn't support optimizing for 386 real mode.
# TODO: change CFLAGS when -mtune=i386/-march=i386 becomes available
CFLAGS := $(CFLAGS) -mtune=i286 -march=i286

ASFLAGS = -f elf
LDFLAGS =
LDLIBS = -L$(dir $(shell $(CC) --print-libgcc-file-name)) -lgcc
ARFLAGS =

DISK_ROOT_DIRECTORY = $(PROJECT_ROOT_DIR)/diskroot

CP = cp -R
RM = rm -f
MKDIR = mkdir -p
