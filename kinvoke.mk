$(_UNIT_NAME)_OBJS := $(addsuffix $(_OBJEXT),$(addprefix $($(_UNIT_NAME)_OUTPUT)/,$(basename $(SRCS))))
$(_UNIT_NAME)_KMOD := $($(_UNIT_NAME)_OUTPUT)/$(KMOD)$(KMOD_EXT)
KDIR := /lib/modules/$(shell uname -r)/build

ifneq ($(_NO_RULES),T)
ifneq ($($(_UNIT_NAME)_DEFINED),T)

all: $($(_UNIT_NAME)_KMOD
	make -C $(KDIR) M=$(_UNIT_PATH)

.PHONY: clean $(_CLEAN)
clean: $(_CLEAN)
	make -C $(KDIR) M=$(_UNIT_PATH) clean

endif
endif
