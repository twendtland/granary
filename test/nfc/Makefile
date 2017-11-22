
ELF = TestNfc
FORMAT = .hex
BINARY = $(addsuffix $(FORMAT), $(ELF))

DEVICE=nrf52

SRCDIR = .
INCDIR = ../../devices/$(DEVICE)/inc
GRANARY_DIR = ../../

CCPATH = /opt/gcc6-arm-none-eabi/bin/

CC = $(CCPATH)/arm-none-eabi-c++
OBJDUMP = $(CCPATH)/arm-none-eabi-objdump
OBJCOPY = $(CCPATH)/arm-none-eabi-objcopy
SIZE = $(CCPATH)/arm-none-eabi-size

INCLUDES += -I$(INCDIR) -I../../../rye/inc -I../ -I../../util/inc -I$(INCDIR)/registers
INCLUDES += -I../../cmsis/include  -I../../cmsis/

SOURCES = $(wildcard *.cpp)
SOURCES += $(wildcard $(GRANARY_DIR)/util/src/*.cpp)

LDFLAGS += -mthumb -T../../devices/nrf52/nrf52.ld -specs=nano.specs -specs=nosys.specs -lc
LDFLAGS += -mcpu=cortex-m4
LDFLAGS += -Wl,--gc-sections

BUILD_DIR = build

CFLAGS = -Os -g -Wall $(INCLUDES) -std=c++14 $(LDFLAGS) -fno-exceptions -fno-rtti

all: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(BUILD_DIR)/$(ELF)
	$(OBJCOPY) -O binary $(BUILD_DIR)/$(ELF)  $(BUILD_DIR)/$(BINARY)
	$(SIZE) $(BUILD_DIR)/$(ELF)

clean:
	rm -f $(BUILD_DIR)/*
	rm -rf asm.s
