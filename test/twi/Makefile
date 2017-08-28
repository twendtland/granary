
EXECUTABLE = TestTwi

DEVICE=nrf52

SRCDIR = .
INCDIR = ./../../devices/$(DEVICE)/inc

CCPATH = /gcc/bin

CC = $(CCPATH)/arm-none-eabi-c++
OBJDUMP = $(CCPATH)/arm-none-eabi-objdump
SIZE = $(CCPATH)/arm-none-eabi-size

INCLUDES += -I$(INCDIR) -I../../../rye/inc -I../ -I../../util/inc -I../../devices/$(DEVICE)/inc/registers \

CFLAGS = -Os -g -Wall $(INCLUDES) -std=c++14 -nostdlib -mcpu=cortex-m3 -mthumb

$(EXECUTABLE): $(EXECUTABLE).cpp
	$(CC) $(CFLAGS) $< -o $(EXECUTABLE)
	$(OBJDUMP) -fd $(EXECUTABLE) > asm.s
	$(SIZE) $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)
	rm -f asm.s
