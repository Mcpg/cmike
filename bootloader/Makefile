
include ../config.mk

ASFLAGS = -f BIN

SOURCE = bootloader.asm
TARGET = bootloader.bin

.PHONY: all clean

all: $(TARGET)

clean:
	$(RM) $(TARGET)

$(TARGET): $(SOURCE)
	$(AS) $(ASFLAGS) $< -o $@
