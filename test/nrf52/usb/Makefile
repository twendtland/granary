
NAME = TestUsb

BUILDDIR = build

BIN = $(BUILDDIR)/$(addsuffix .bin, $(NAME))
ELF = $(BUILDDIR)/$(addsuffix .elf, $(NAME))
HEX = $(BUILDDIR)/$(addsuffix .hex, $(NAME))
DEVICE = nrf52

GRANARY_DIR = ../../..
SRCDIR = .
INCDIR = $(GRANARY_DIR)/devices/$(DEVICE)/inc

CCPATH = /opt/gcc/bin

CC = $(CCPATH)/arm-none-eabi-c++
LD = $(CCPATH)/arm-none-eabi-ld
OBJDUMP = $(CCPATH)/arm-none-eabi-objdump
OBJCOPY = $(CCPATH)/arm-none-eabi-objcopy
SIZE = $(CCPATH)/arm-none-eabi-size

INCLUDES = -I$(INCDIR) -I../$(GRANARY_DIR)/rye/inc -I../ -I$(GRANARY_DIR)/util/inc -I$(INCDIR)/registers -I$(GRANARY_DIR)/devices/$(DEVICE)/
INCLUDES += -I$(GRANARY_DIR)/cmsis/include -I$(GRANARY_DIR)/cmsis/

SOURCES = $(wildcard *.cpp)
SOURCES += $(wildcard $(GRANARY_DIR)/util/src/*.cpp)

OBJECTS += $(addsuffix .o, $(basename $(SOURCES)))

CFLAGS = -mthumb -mcpu=cortex-m4 -O0 -g -Wall -Wpedantic $(INCLUDES) -std=c++14 -nostdlib $(LDFLAGS) -fno-exceptions -fno-rtti

LDSCRIPT = $(GRANARY_DIR)/devices/nrf52/nrf52.ld
LDFLAGS = -T$(LDSCRIPT)

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
