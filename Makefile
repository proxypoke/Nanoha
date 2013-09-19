# Makefile - you know what this does.
#
# This file is part of Nanoha.
#
# Nanoha is Free Software under the non-terms of
# the Anti-License. Do whatever the fuck you want.

.PHONY: all
all: link

setup:
	@mkdir -p build

.PHONY: boot
boot: setup
	@echo "Assembling boot.s..."
	@i586-elf-as boot/boot.s -o build/boot.o

.PHONY: kernel
kernel: setup
	@echo "Compiling kernel..."
	@i586-elf-gcc -c kernel/kernel_main.c \
		-o build/kernel.o \
		-std=c99 \
		-ffreestanding \
		-O2 -Wall -Wextra

.PHONY: link
link: boot kernel
	@echo "Linking kernel..."
	@i586-elf-gcc -T kernel/linker.ld \
		-o build/nanoha.bin \
		-ffreestanding \
		-O2 \
		-nostdlib \
		-lgcc \
		build/boot.o \
		build/kernel.o

.PHONY: clean
clean:
	rm -f *.[1-8]
	rm -rf build

.PHONY: man
man:
	a2x --no-xmllint --format manpage README.asciidoc
