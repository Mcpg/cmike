
PROJECT_ROOT_DIR = $(shell pwd)
BUILD_MODULES ?= kernel diskimg
AUTO_MODULES ?= kernel

include config.mk

export

.PHONY: all clean $(BUILD_MODULES)

all: $(AUTO_MODULES)

clean: $(addsuffix _clean,$(BUILD_MODULES))

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
