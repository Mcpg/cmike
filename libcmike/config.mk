SRC_DIR = src
BIN_DIR = bin
INCLUDE_DIR = include

RESULT_FILE = libcmike.a

CFLAGS += -I$(INCLUDE_DIR)
ASFLAGS += -i$(INCLUDE_DIR)/
ARFLAGS += rcs
