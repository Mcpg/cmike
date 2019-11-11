include ../config.mk
include config.mk
include ../common.mk

all: $(RESULT_FILE)

clean:
	$(RM) $(RESULT_FILE) $(OBJECTS)

$(RESULT_FILE): $(LINKER_SCRIPT) $(OBJECTS)
	-@$(MKDIR) $(dir $@)
	$(LD) $(LDFLAGS) -o $@ -T $^ $(LDLIBS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	-@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

$(BIN_DIR)/%.o: $(SRC_DIR)/%.asm
	-@$(MKDIR) $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<
