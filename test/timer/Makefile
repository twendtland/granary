
EXECUTABLE = TestTimer

DEVICE=nrf52

SRCDIR = .
INCDIR = ./../../devices/$(DEVICE)/inc

CCPATH = /gcc/bin

CC = $(CCPATH)/arm-none-eabi-c++
OBJDUMP = $(CCPATH)/arm-none-eabi-objdump
SIZE = $(CCPATH)/arm-none-eabi-size

INCLUDES += -I$(INCDIR) -I../../../rye/inc -I../ -I../../util/inc -I../../devices/$(DEVICE)/inc/registers
INCLUDES += -I../../cmsis/include  -I../../cmsis/

LDFLAGS += -mthumb -Tnrf52/nrf52.ld -specs=nano.specs -specs=nosys.specs -lc
LDFLAGS += -mcpu=cortex-m4
LDFLAGS += -Wl,--gc-sections

CFLAGS = -Os -g -Wall $(INCLUDES) -std=c++14 $(LDFLAGS) -fno-exceptions -fno-rtti

$(EXECUTABLE): $(EXECUTABLE).cpp
	$(CC) $(CFLAGS) $< -o $(EXECUTABLE)
	$(OBJDUMP) -fd $(EXECUTABLE) > asm.s
	$(SIZE) $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)
	rm -f asm.s
