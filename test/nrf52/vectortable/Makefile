
ELF = TestVectorTable
FORMAT = .hex
BINARY = $(addsuffix $(FORMAT), $(ELF))

DEVICE=nrf52

GRANARY_DIR = ../../..
SRCDIR = .
INCDIR = $(GRANARY_DIR)/devices/$(DEVICE)/inc

CCPATH = /opt/gcc/bin/

CC = $(CCPATH)/arm-none-eabi-c++
OBJDUMP = $(CCPATH)/arm-none-eabi-objdump
OBJCOPY = $(CCPATH)/arm-none-eabi-objcopy
SIZE = $(CCPATH)/arm-none-eabi-size

INCLUDES += -I$(INCDIR) -I../$(GRANARY_DIR)/rye/inc -I../ -I$(GRANARY_DIR)/util/inc -I$(INCDIR)/registers
INCLUDES += -I$(GRANARY_DIR)/cmsis/include  -I$(GRANARY_DIR)/cmsis/

SOURCES = $(wildcard *.cpp)
SOURCES += $(wildcard $(GRANARY_DIR)/util/src/*.cpp)

LDFLAGS += -mthumb -T$(GRANARY_DIR)/devices/nrf52/nrf52.ld -specs=nano.specs -specs=nosys.specs -lc
LDFLAGS += -mcpu=cortex-m4
LDFLAGS += -Wl,--gc-sections

BUILD_DIR = build

CFLAGS = -Os -g -Wall $(INCLUDES) -std=c++14 $(LDFLAGS) -fno-exceptions -fno-rtti

all: $(SOURCES)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SOURCES) -o $(BUILD_DIR)/$(ELF)
	$(OBJCOPY) -O binary $(BUILD_DIR)/$(ELF)  $(BUILD_DIR)/$(BINARY)
	$(SIZE) $(BUILD_DIR)/$(ELF)

clean:
	rm -f $(BUILD_DIR)/*
	rm -rf asm.s
