include config.mk

SOURCES =
define INCLUDE_DIRECTORY
$(eval include $1/subdir.mk)
$(eval SOURCES := $(SOURCES) $(patsubst $(SRC_DIR)/%,%,$(addprefix $1/,$(LOCAL_SOURCES))))
$(eval $(foreach directory,$(LOCAL_DIRECTORIES),$(eval $(call INCLUDE_DIRECTORY,$1/$(directory)))))
endef
$(eval $(call INCLUDE_DIRECTORY,$(SRC_DIR)))

OBJECTS = $(patsubst %.asm,$(BIN_DIR)/%.o,$(patsubst %.c,$(BIN_DIR)/%.o,$(SOURCES)))

all: $(RESULT_FILE)

clean:
	$(RM) $(RESULT_FILE) $(OBJECTS)

$(RESULT_FILE): $(LINKER_SCRIPT) $(OBJECTS)
	-@$(MKDIR) $(dir $@)
	$(LD) $(LDFLAGS) -o $@ -T $^

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	-@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

$(BIN_DIR)/%.o: $(SRC_DIR)/%.asm
	-@$(MKDIR) $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<
