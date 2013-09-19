# Makefile - you know what this does.
#
# This file is part of Nanoha.
#
# Nanoha is Free Software under the non-terms of
# the Anti-License. Do whatever the fuck you want.

CC := i586-elf-gcc
AS := i586-elf-as

DIRS := boot include kernel lib

SRCFILES := $(shell find $(DIRS) -type f -name "*.c")
HDRFILES := $(shell find $(DIRS) -type f -name "*.h")
ASMFILES := $(shell find $(DIRS) -type f -name "*.s")

OBJFILES := $(patsubst %.c,%.o,$(SRCFILES)) $(patsubst %.s,%-asm.o,$(ASMFILES))
DEPFILES    := $(patsubst %.c,%.d,$(SRCFILES))


WARNINGS := -Wall -Wextra #-pedantic -Wshadow -Wpointer-arith -Wcast-align \
            -Wwrite-strings -Wmissing-prototypes -Wmissing-declarations \
            -Wredundant-decls -Wnested-externs -Winline -Wno-long-long \
            -Wuninitialized -Wconversion -Wstrict-prototypes
CFLAGS := -g -std=c99 $(WARNINGS) -Iinclude -ffreestanding -O2


.PHONY: all clean

all: nanoha.bin

nanoha.bin: linker.ld $(OBJFILES)
	@$(CC) -T linker.ld \
		-o nanoha.bin \
		-ffreestanding \
		-O2 \
		-nostdlib \
		-lgcc \
		$(OBJFILES)

clean:
	-@$(RM) $(wildcard $(OBJFILES) $(DEPFILES) nanoha.bin)


# Dependenies

-include $(DEPFILES)

# Makefile is listed as a dep in case the CFLAGS are changed
%.o: %.c Makefile
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

%-asm.o: %.s Makefile
	@$(AS) $< -o $@


# QEMU utility

qemu-runkernel: nanoha.bin
	@qemu-system-i386 -kernel nanoha.bin
