
PROJECT_ROOT_DIR = $(shell pwd)
BUILD_MODULES ?= bootloader kernel libcmike programs diskimg
AUTO_MODULES ?= bootloader kernel libcmike programs diskimg

include config.mk

export

.PHONY: all clean run $(BUILD_MODULES)

all: $(AUTO_MODULES)

clean: $(addsuffix _clean,$(BUILD_MODULES))

run:
	qemu-system-i386 -soundhw pcspk -drive format=raw,file=diskimg/cmike.flp,index=0,if=floppy

#######################################

# $1 - module name
define MODULE_TEMPLATE

$(1):
	$(MKDIR) $(DISK_ROOT_DIRECTORY)
	$(MAKE) -C $(1) all

$(1)_clean:
	$(MAKE) -C $(1) clean

endef

$(foreach module,$(BUILD_MODULES),$(eval $(call MODULE_TEMPLATE,$(module))))
