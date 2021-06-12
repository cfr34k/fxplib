# --- START OF CONFIG ---------------------------------------------------
# Edit the following variables for your own needs

# toolchain configuration
PREFIX  ?=
CC       = $(PREFIX)gcc
LD       = $(PREFIX)gcc
AR       = $(PREFIX)ar

# default build configuration
# "make BUILD=release" does a release build
BUILD:=debug

# basic build flags configuration (CFLAGS should be set from outside Makefile)
CFLAGS+=-Wall -std=c99 -pedantic \
        -Iinclude

# target configuration
POSTFIX ?= default
TARGET := libfxp_$(POSTFIX)
VERSION := 0.0.0
VCSVERSION := $(shell git rev-parse --short HEAD)

# source files for the project
SOURCE := $(shell find src/ -name '*.c')
INCLUDES := $(shell find include/ src/ -name '*.h')

# additional dependencies for build (proper targets must be specified by user)
DEPS :=

# default target
all: $(TARGET)

# user-specific targets

# --- END OF CONFIG -----------------------------------------------------

OBJ1=$(patsubst %.c, %.o, $(SOURCE))
OBJ=$(patsubst src/%, obj/$(BUILD)/%, $(OBJ1))

VERSIONSTR="\"$(VERSION)-$(VCSVERSION)\""

CFLAGS+=-DVERSION=$(VERSIONSTR)

TARGET_BASE := lib/$(BUILD)/$(TARGET)

CFLAGS+=$(CFLAGS_$(BUILD))
LDFLAGS+=$(LDFLAGS_$(BUILD))

.PHONY show_cflags:
	@echo --- Build parameters:  ------------------------------------------
	@echo CFLAGS\=$(CFLAGS)
	@echo SOURCE\=$(SOURCE)
	@echo -----------------------------------------------------------------

$(TARGET): show_cflags $(TARGET_BASE).a
	@echo ">>> $(BUILD) build complete."

$(TARGET_BASE).a: $(DEPS) $(OBJ) $(INCLUDES) Makefile
	@echo Packing $@ ...
	@mkdir -p $(shell dirname $@)
	@rm -f $(TARGET_BASE).a
	@$(AR) r $(TARGET_BASE).a $(OBJ)

obj/$(BUILD)/%.o: src/%.c $(INCLUDES) Makefile
	@echo "Compiling $< ..."
	@mkdir -p $(shell dirname $@)
	@$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET_BASE).a
	rm -f $(OBJ)
