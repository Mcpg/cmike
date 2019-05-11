
include ../config.mk
include config.mk

export

.PHONY: all clean floppy

all: floppy

clean:
	$(RM) $(FLOPPY_IMG_PATH)

floppy:
	@./floppy.sh