exe=$1 # first commandline argument has to be file with debug symbols

arm-none-eabi-gdb --se=$exe --command=./gdbcmds
