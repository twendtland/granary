
EXECUTABLE = TestVectorTable

DEVICE=nrf52

SRCDIR = .
INCDIR = ./../../devices/$(DEVICE)/inc

CCPATH = /opt/gcc6-arm-none-eabi/bin

CC = $(CCPATH)/arm-none-eabi-c++
OBJDUMP = $(CCPATH)/arm-none-eabi-objdump
SIZE = $(CCPATH)/arm-none-eabi-size
LINKERSCRIPT=linker.ld

INCLUDES += -I$(INCDIR) -I../../../rye/inc -I../ -I../../util/inc -I../../devices/$(DEVICE)/inc/registers \

CFLAGS = -Os -g -Wall $(INCLUDES) -std=c++14 -nostdlib -mcpu=cortex-m3 -mthumb -T$(LINKERSCRIPT) -fno-exceptions

$(EXECUTABLE): $(EXECUTABLE).cpp
	$(CC) $(CFLAGS) $< -o $(EXECUTABLE)
	$(OBJDUMP) -d $(EXECUTABLE) -j.text -j.isr_vector > asm.s
	$(SIZE) $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)
