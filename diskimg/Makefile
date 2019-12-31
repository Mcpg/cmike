
include ../config.mk
include config.mk

.PHONY: all clean floppy $(FLOPPY_IMG_PATH)

all: floppy

clean:
	$(RM) $(FLOPPY_IMG_PATH)

floppy: $(FLOPPY_IMG_PATH)

$(FLOPPY_IMG_PATH):
	$(DD) if=/dev/zero of=$@ bs=512 count=2880
	$(DD) if=$(PROJECT_ROOT_DIR)/bootloader/bootloader.bin of=$@ bs=512 count=1 conv=notrunc
	$(MCOPY) -i $@ $(DISK_ROOT_DIRECTORY)/** ::/
