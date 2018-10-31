
target remote 127.0.0.1:2331

load build/TestUsb.elf

file build/TestUsb.elf

monitor reset

set confirm off

quit
