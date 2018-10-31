
# Basic makefile for all tests

BUILDDIR = build

NAME = Test
DEVICE = nrf52

BIN = $(BUILDDIR)/$(addsuffix .bin, $(NAME))
ELF = $(BUILDDIR)/$(addsuffix .elf, $(NAME))
HEX = $(BUILDDIR)/$(addsuffix .hex, $(NAME))
ASM = $(BUILDDIR)/asm.txt

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

CFLAGS = -mthumb -mcpu=cortex-m4 -Os -Wall -Wpedantic $(INCLUDES) -std=c++14 -ffreestanding -fno-exceptions -fno-rtti -ffunction-sections -fdata-sections

LDSCRIPT = $(GRANARY_DIR)/devices/$(DEVICE)/linkerscript.ld
LDFLAGS = -T$(LDSCRIPT)

all: $(ELF) $(HEX) $(BIN)

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@

$(HEX): $(ELF)
	$(OBJCOPY) -O ihex $< $@

$(ELF): $(OBJECTS) $(LDSCRIPT)
	$(LD) $(LDFLAGS) -o $@ $(OBJECTS)
	rm -rf $(OBJECTS)

%.o: %.cpp
	mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(BUILDDIR)
	rm -rf $(OBJECTS)
	rm -f $(ASM)

asm: $(ELF)
	$(OBJDUMP) -fhd $(ELF) > $(ASM)

flash:
	../../gdbclient.sh ../flash.gdb

debug:
	../../gdbclient.sh ../debug.gdb
