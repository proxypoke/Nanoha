# This file is part of Nanoha.
#
# Nanoha is Free Software under the non-terms of
# the Anti-Licencse. Do whatever the fuck you want.

target remote localhost:1234

# This requires the auto-load-path of gdb to be modified to run work correctly.
# To do this, put the following in your ~/.gdbinit:
#   add-auto-load-safe-path /path/to/this/directory/.gdbinit
symbol-file nanoha.bin
