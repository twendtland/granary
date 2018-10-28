
# Basic makefile for all tests

BUILDDIR = build

BIN = $(BUILDDIR)/$(addsuffix .bin, $(NAME))
ELF = $(BUILDDIR)/$(addsuffix .elf, $(NAME))
HEX = $(BUILDDIR)/$(addsuffix .hex, $(NAME))

GRANARY_DIR = ../../..
SRCDIR = .
INCDIR = $(GRANARY_DIR)/devices/$(DEVICE)/inc

CCPREFIX = arm-none-eabi-

CC = $(CCPREFIX)c++
LD =  $(CCPREFIX)ld
OBJDUMP =  $(CCPREFIX)objdump
OBJCOPY =  $(CCPREFIX)objcopy
SIZE =  $(CCPREFIX)size

INCLUDES = -I$(INCDIR) -I../$(GRANARY_DIR)/rye/inc -I../ -I$(GRANARY_DIR)/util/inc -I$(INCDIR)/registers -I$(GRANARY_DIR)/devices/$(DEVICE)/
INCLUDES += -I$(GRANARY_DIR)/cmsis/include -I$(GRANARY_DIR)/cmsis/

SOURCES = $(wildcard *.cpp)
SOURCES += $(wildcard $(GRANARY_DIR)/util/src/*.cpp)

OBJECTS += $(addsuffix .o, $(basename $(SOURCES)))

LDSCRIPT = $(GRANARY_DIR)/devices/nrf52/nrf52.ld
LDFLAGS = -T$(LDSCRIPT)

CFLAGS = -mthumb -mcpu=cortex-m4 -O0 -g -Wall -Wpedantic $(INCLUDES) -std=c++14 -nostdlib $(LDFLAGS) -fno-exceptions -fno-rtti

all: $(ELF)

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@

$(HEX): $(ELF)
	$(OBJCOPY) -O ihex $< $@

$(ELF): $(OBJECTS) $(LDSCRIPT)
	$(LD) $(LDFLAGS) -o $@ $(OBJECTS) $(LDLIBS)

%.o: %.cpp
	mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(BUILDDIR)
	rm -rf $(OBJECTS)

asm: $(ELF)
	$(OBJDUMP) -fhD $(ELF) > asm.txt
