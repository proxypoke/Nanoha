# Makefile - you know what this does.
#
# This file is part of Nanoha.
#
# Nanoha is Free Software under the non-terms of
# the Anti-License. Do whatever the fuck you want.

.PHONY: all
all: 
	@echo "Nothing to see here (yet), move along."

.PHONY: clean
clean:
	rm -f *.[1-8]

.PHONY: man
man:
	a2x --no-xmllint --format manpage README.asciidoc
