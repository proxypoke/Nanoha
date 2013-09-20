# Makefile - you know what this does.
#
# This file is part of Nanoha.
#
# Nanoha is Free Software under the non-terms of
# the Anti-License. Do whatever the fuck you want.

CC := i586-elf-gcc
AS := i586-elf-as
AR := i586-elf-ar

DIRS := boot include kernel lib

SRCFILES := $(shell find $(DIRS) -type f -name "*.c")
HDRFILES := $(shell find $(DIRS) -type f -name "*.h")
ASMFILES := $(shell find $(DIRS) -type f -name "*.s")

OBJFILES := $(patsubst %.c,%.o,$(SRCFILES)) $(patsubst %.s,%-asm.o,$(ASMFILES))
DEPFILES := $(patsubst %.c,%.d,$(SRCFILES))

LIBCSRC := $(shell find libc -type f -name "*.c")
LIBCHDR := $(shell find libc -type f -name "*.h")

LIBCOBJ := $(patsubst %.c, %.o, $(LIBCSRC))
LIBCDEP := $(patsubst %.c, %.d, $(LIBCSRC))

WARNINGS := -Wall -Wextra #-pedantic -Wshadow -Wpointer-arith -Wcast-align \
            -Wwrite-strings -Wmissing-prototypes -Wmissing-declarations \
            -Wredundant-decls -Wnested-externs -Winline -Wno-long-long \
            -Wuninitialized -Wconversion -Wstrict-prototypes
CFLAGS := -g -std=c99 $(WARNINGS) -O2

.PHONY: all clean

all: nanoha.bin

nanoha.bin: linker.ld libc/libc.a $(OBJFILES)
	@$(CC) -T linker.ld \
		-o nanoha.bin \
		-ffreestanding \
		-O2 \
		-nostdlib \
		-lgcc \
		$(OBJFILES) \
		libc/libc.a

libc/libc.a: $(LIBCOBJ)
	@$(AR) -cvq libc/libc.a $(LIBCOBJ)

clean:
	-@$(RM) $(wildcard $(OBJFILES) $(DEPFILES) nanoha.bin)
	-@$(RM) $(wildcard $(LIBCOBJ) $(LIBCDEP) libc/libc.a)


# Dependenies

-include $(DEPFILES)
-include $(LIBCDEP)

# Makefile is listed as a dep in case the CFLAGS are changed
%.o: %.c Makefile
	@$(CC) $(CFLAGS) -Iinclude -Ilibc/include \
		-ffreestanding -MMD -MP -c $< -o $@

%-asm.o: %.s Makefile
	@$(AS) $< -o $@

libc/%.o: libc/%.c Makefile
	@$(CC) $(CFLAGS) -Ilibc/include -MMD -MP -c $< -o $@


# QEMU utility

qemu-runkernel: nanoha.bin
	@qemu-system-i386 -kernel nanoha.bin

qemu-debug: nanoha.bin
	@qemu-system-i386 -s -S -kernel nanoha.bin
