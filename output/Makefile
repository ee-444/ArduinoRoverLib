###############################################################################
# Makefile for the project Arduino
###############################################################################

## General Flags
PROJECT = Arduino
MCU = atmega328p
TARGET = Arduino.elf
CC = avr-gcc

CPP = avr-g++

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2   -std=c99                        -DF_CPU=16000000UL -O2 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=Arduino.map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Include Directories
INCLUDES = -I"B:\atmel_projects\ArduinoRoverLib\source" -I"B:\atmel_projects\ArduinoRoverLib\library" 

## Objects that must be built in order to link
OBJECTS = main.o pins_arduino.o WInterrupts.o wiring.o wiring_analog.o wiring_digital.o wiring_pulse.o wiring_shift.o HardwareSerial.o Print.o Tone.o WMath.o WString.o cplusplushelper.o Wire.o EEPROM.o AFMotor.o twi.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) Arduino.hex Arduino.eep Arduino.lss size

## Compile
main.o: ../source/main.cpp
	$(CPP) $(INCLUDES) $(CFLAGS) -c  $<

pins_arduino.o: ../library/pins_arduino.c
	$(CPP) $(INCLUDES) $(CFLAGS) -c  $<

WInterrupts.o: ../library/WInterrupts.c
	$(CPP) $(INCLUDES) $(CFLAGS) -c  $<

wiring.o: ../library/wiring.c
	$(CPP) $(INCLUDES) $(CFLAGS) -c  $<

wiring_analog.o: ../library/wiring_analog.c
	$(CPP) $(INCLUDES) $(CFLAGS) -c  $<

wiring_digital.o: ../library/wiring_digital.c
	$(CPP) $(INCLUDES) $(CFLAGS) -c  $<

wiring_pulse.o: ../library/wiring_pulse.c
	$(CPP) $(INCLUDES) $(CFLAGS) -c  $<

wiring_shift.o: ../library/wiring_shift.c
	$(CPP) $(INCLUDES) $(CFLAGS) -c  $<

HardwareSerial.o: ../library/HardwareSerial.cpp
	$(CPP) $(INCLUDES) $(CFLAGS) -c  $<

Print.o: ../library/Print.cpp
	$(CPP) $(INCLUDES) $(CFLAGS) -c  $<

Tone.o: ../library/Tone.cpp
	$(CPP) $(INCLUDES) $(CFLAGS) -c  $<

WMath.o: ../library/WMath.cpp
	$(CPP) $(INCLUDES) $(CFLAGS) -c  $<

WString.o: ../library/WString.cpp
	$(CPP) $(INCLUDES) $(CFLAGS) -c  $<

cplusplushelper.o: ../library/cplusplushelper.cpp
	$(CPP) $(INCLUDES) $(CFLAGS) -c  $<

Wire.o: ../library/Wire.cpp
	$(CPP) $(INCLUDES) $(CFLAGS) -c  $<

EEPROM.o: ../library/EEPROM.cpp
	$(CPP) $(INCLUDES) $(CFLAGS) -c  $<

AFMotor.o: ../library/AFMotor.cpp
	$(CPP) $(INCLUDES) $(CFLAGS) -c  $<

twi.o: ../library/twi.c
	$(CPP) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CPP) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

size: ${TARGET}
	@echo
	@avr-size -C --mcu=${MCU} ${TARGET}

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) Arduino.elf dep/* Arduino.hex Arduino.eep Arduino.lss Arduino.map


## Other dependencies
-include $(shell mkdir dep 2>NUL) $(wildcard dep/*)

