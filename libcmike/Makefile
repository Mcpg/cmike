include ../config.mk
include config.mk
include ../common.mk

all: $(RESULT_FILE)

clean:
	$(RM) $(RESULT_FILE) $(OBJECTS)

$(RESULT_FILE): $(OBJECTS)
	-@$(MKDIR) $(dir $@)
	$(AR) $(ARFLAGS) $@ $^

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	-@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

$(BIN_DIR)/%.o: $(SRC_DIR)/%.asm
	-@$(MKDIR) $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<
