
EXECUTABLE = test

SRCDIR = .
INCDIR = ./../../inc

CCPATH = /opt/gcc6-arm-none-eabi/bin

CC = $(CCPATH)/arm-none-eabi-c++
OBJDUMP = $(CCPATH)/arm-none-eabi-objdump
SIZE = $(CCPATH)/arm-none-eabi-size

INCLUDES += -I$(INCDIR) -I../../rye/inc -I../ -I../util/inc -I../devices/nrf52/inc -I../devices/nrf52/inc/registers \

CFLAGS = -Os -g -Wall $(INCLUDES) -std=c++14 -nostdlib -mcpu=cortex-m3 -mthumb

all:

clean:
	rm $(EXECUTABLE) -f
