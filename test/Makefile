
EXECUTABLE = test

SRCDIR = .
INCDIR = ./../../inc

CCPATH = /opt/gcc6-arm-none-eabi/bin

CC = $(CCPATH)/arm-none-eabi-c++
OBJDUMP = $(CCPATH)/arm-none-eabi-objdump

INCLUDES += -I$(INCDIR) -I../../rye/header -I../../rye/inc -I../ -I../util \

CFLAGS = -Os -g -Wall $(INCLUDES) -std=c++14 -nostdlib -mcpu=cortex-m3 -mthumb

$(EXECUTABLE): test.cpp
	$(CC) $(CFLAGS) $< -o $(EXECUTABLE)
	$(OBJDUMP) -d test > asm.s

clean:
	rm $(EXECUTABLE)
