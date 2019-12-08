
include ../config.mk

BIN_DIR = bin

LIBCMIKE = $(PROJECT_ROOT_DIR)/libcmike/libcmike.a
LDLIBS += $(LIBCMIKE)
LDFLAGS += -T $(PROJECT_ROOT_DIR)/libcmike/cmikeprog.ld
CFLAGS += -I$(PROJECT_ROOT_DIR)/libcmike/include $(LDFLAGS)

SOURCES = $(wildcard *.c)
PROGRAMS = $(patsubst %.c,$(BIN_DIR)/%.bin,$(SOURCES))

.PHONY: all clean copy_to_disk

all: $(PROGRAMS) copy_to_disk

clean:
	$(RM) $(PROGRAMS)

copy_to_disk: $(PROGRAMS)
	$(foreach prg,$(PROGRAMS),$(CP) $(prg) $(DISK_ROOT_DIRECTORY);)

$(BIN_DIR)/%.bin: %.c
	-@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) $< -o $@ $(LDLIBS)
