
SRC_DIR = src
BIN_DIR = bin
INCLUDE_DIR = include

RESULT_FILE = $(DISK_ROOT_DIRECTORY)/KERNEL.BIN
LINKER_SCRIPT = $(SRC_DIR)/cmike.ld

CFLAGS += -I$(INCLUDE_DIR)
ASFLAGS += -i$(INCLUDE_DIR)/
