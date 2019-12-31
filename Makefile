
PROJECT_ROOT_DIR = $(shell pwd)
BUILD_MODULES ?= bootloader kernel libcmike diskimg programs
AUTO_MODULES ?= bootloader kernel libcmike diskimg programs

include config.mk

export

.PHONY: all clean run $(BUILD_MODULES)

all: $(AUTO_MODULES)

clean: $(addsuffix _clean,$(BUILD_MODULES))

run:
	qemu-system-i386 -fda diskimg/cmike.flp -soundhw pcspk

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
