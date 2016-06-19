# Use host toolchain
PREFIX   =
CC       = $(PREFIX)gcc
LD       = $(PREFIX)gcc
AR       = $(PREFIX)ar

POSTFIX=test

export PREFIX POSTFIX

# distinguishable output

LIBFXP = ../lib/debug/libfxp_test.a

CFLAGS = -Wall -std=c99 -pedantic -ggdb -I../src
LDFLAGS = -L../lib/debug -lfxp_test

all: build_libfxp test_libfxp

.PHONY: build_libfxp
build_libfxp:
	cd .. && $(MAKE)

test_libfxp: test_libfxp.o $(LIBFXP)
	$(LD) -o $@ $< $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf ../lib ../obj
	rm -f test_libfxp test_libfxp.o
