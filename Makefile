CC=gcc
AS=as

ARCH=amd64

CFLAGS=-Wall -pipe -Iinclude/ -std=c99 -nostdlib -ffreestanding $(OPTIMIZATION)
ASFLAGS=--64

OPTIMIZATION=-O2

DEBUG = no
ifeq ($(DEBUG), yes)
	CFLAGS += -g
endif

MLIBC_SOURCES=$(wildcard src/*.c)
MLIBC_SOURCES+=$(wildcard arch/${ARCH}/*.S)

TMP_OBJECTS=$(MLIBC_SOURCES:.c=.o)
MLIBC_OBJECTS=$(TMP_OBJECTS:.S=.o)

LIB_DIR=lib

mlibc: $(MLIBC_OBJECTS)
	ar rcs $(LIB_DIR)/libminimalc.a $(MLIBC_OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.S
	$(AS) $(ASFLAGS) $< -o $@

clean:
	find . -type f \( -name "*.o" -o -name "*.a" \) -exec rm {} \;

.PHONY: clean
