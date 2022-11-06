_OUTTOP ?= target

.PHONY: all
all:

# _ROOT=$(shell (while [[ ! -f root.mk ]] && [[ $PWD != / ]]; do \cd ..; done; if [[ -f root.mk ]];then echo $PWD/root.mk;fi))
_ROOT=$(CURDIR)
_MAKEFILES := $(filter %/Makefile,$(MAKEFILE_LIST))
_INCLUDED_FROM := $(patsubst $(_ROOT)/%,%,$(if $(_MAKEFILES),$(patsubst %/Makefile,%,$(word $(words $(_MAKEFILES)),$(_MAKEFILES)))))

ifeq ($(_INCLUDED_FROM),)
	_UNIT := $(patsubst $(_ROOT)/%,%,$(CURDIR))
else
	_UNIT := $(_INCLUDED_FROM)
endif

_UNIT_PATH := $(_ROOT)/$(_UNIT)
_UNIT_NAME := $(subst /,_,$(_UNIT))
$(_UNIT_NAME)_OUTPUT := $(_OUTTOP)/$(_UNIT)

_KMODEXT := .ko
