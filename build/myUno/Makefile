ifeq ($(OS),Windows_NT)
SHELL = cmd
RMDIR = rmdir /s /q
RM = del /q
mymkdir = if not exist "$1" mkdir "$1"
else
RMDIR = rm -fr
RM = rm -f
mymkdir = mkdir -p $1
endif

PROJECT_OBJS = \
	project/LedLights.cpp.o \
	project/Util.cpp.o \

PLATFORM_CORE_OBJS = \
	core/abi.cpp.o \
	core/CDC.cpp.o \
	core/HardwareSerial.cpp.o \
	core/HardwareSerial0.cpp.o \
	core/HardwareSerial1.cpp.o \
	core/HardwareSerial2.cpp.o \
	core/HardwareSerial3.cpp.o \
	core/hooks.c.o \
	core/IPAddress.cpp.o \
	core/main.cpp.o \
	core/new.cpp.o \
	core/PluggableUSB.cpp.o \
	core/Print.cpp.o \
	core/Stream.cpp.o \
	core/Tone.cpp.o \
	core/USBCore.cpp.o \
	core/WInterrupts.c.o \
	core/wiring.c.o \
	core/wiring_analog.c.o \
	core/wiring_digital.c.o \
	core/wiring_pulse.c.o \
	core/wiring_pulse.S.o \
	core/wiring_shift.c.o \
	core/WMath.cpp.o \
	core/WString.cpp.o \

PLATFORM_VARIANT_OBJS = \

LIBRARIES_OBJS = \
	libraries/Adafruit_NeoPixel/1.1.6/Adafruit_NeoPixel.cpp.o \
	libraries/Adafruit_NeoPixel/1.1.6/esp8266.c.o \
	libraries/Wire/src/utility/twi.c.o \
	libraries/Wire/src/Wire.cpp.o \
	libraries/IRremote/2.2.3/esp32.cpp.o \
	libraries/IRremote/2.2.3/irPronto.cpp.o \
	libraries/IRremote/2.2.3/irRecv.cpp.o \
	libraries/IRremote/2.2.3/IRremote.cpp.o \
	libraries/IRremote/2.2.3/irSend.cpp.o \
	libraries/IRremote/2.2.3/ir_Aiwa.cpp.o \
	libraries/IRremote/2.2.3/ir_Denon.cpp.o \
	libraries/IRremote/2.2.3/ir_Dish.cpp.o \
	libraries/IRremote/2.2.3/ir_JVC.cpp.o \
	libraries/IRremote/2.2.3/ir_Lego_PF.cpp.o \
	libraries/IRremote/2.2.3/ir_LG.cpp.o \
	libraries/IRremote/2.2.3/ir_Mitsubishi.cpp.o \
	libraries/IRremote/2.2.3/ir_NEC.cpp.o \
	libraries/IRremote/2.2.3/ir_Panasonic.cpp.o \
	libraries/IRremote/2.2.3/ir_RC5_RC6.cpp.o \
	libraries/IRremote/2.2.3/ir_Samsung.cpp.o \
	libraries/IRremote/2.2.3/ir_Sanyo.cpp.o \
	libraries/IRremote/2.2.3/ir_Sharp.cpp.o \
	libraries/IRremote/2.2.3/ir_Sony.cpp.o \
	libraries/IRremote/2.2.3/ir_Template.cpp.o \
	libraries/IRremote/2.2.3/ir_Whynter.cpp.o \
	libraries/IRremote/2.2.3/sam.cpp.o \
	libraries/SPI/src/SPI.cpp.o \
	libraries/HID/src/HID.cpp.o \
	libraries/SoftwareSerial/src/SoftwareSerial.cpp.o \

TARGETS = \
	LedLights.hex \

all: $(TARGETS)

LedLights.hex: LedLights.elf
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-objcopy" -O ihex -R .eeprom  "./LedLights.elf" "./LedLights.hex"

LedLights.elf: $(PROJECT_OBJS) $(LIBRARIES_OBJS) core.a
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -w -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega328p  -o "./LedLights.elf" $(PROJECT_OBJS) $(LIBRARIES_OBJS) "./core.a" "-L." -lm

core.a:	$(PLATFORM_CORE_OBJS) $(PLATFORM_VARIANT_OBJS)

clean:
	-$(RMDIR) project core variant libraries
	-$(RM) *.hex *.eep *.bin *.elf *.a *.ar *.d

size:
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-size" -A "./LedLights.elf"

project/LedLights.cpp.o: ../../LedLights.cpp project/LedLights.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

project/LedLights.cpp.d: ;

-include project/LedLights.cpp.d 

project/Util.cpp.o: ../../Util.cpp project/Util.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

project/Util.cpp.d: ;

-include project/Util.cpp.d 


core/abi.cpp.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/abi.cpp core/abi.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/abi.cpp.d: ;

-include core/abi.cpp.d

core/CDC.cpp.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/CDC.cpp core/CDC.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/CDC.cpp.d: ;

-include core/CDC.cpp.d

core/HardwareSerial.cpp.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/HardwareSerial.cpp core/HardwareSerial.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial.cpp.d: ;

-include core/HardwareSerial.cpp.d

core/HardwareSerial0.cpp.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/HardwareSerial0.cpp core/HardwareSerial0.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial0.cpp.d: ;

-include core/HardwareSerial0.cpp.d

core/HardwareSerial1.cpp.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/HardwareSerial1.cpp core/HardwareSerial1.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial1.cpp.d: ;

-include core/HardwareSerial1.cpp.d

core/HardwareSerial2.cpp.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/HardwareSerial2.cpp core/HardwareSerial2.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial2.cpp.d: ;

-include core/HardwareSerial2.cpp.d

core/HardwareSerial3.cpp.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/HardwareSerial3.cpp core/HardwareSerial3.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial3.cpp.d: ;

-include core/HardwareSerial3.cpp.d

core/hooks.c.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/hooks.c core/hooks.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/hooks.c.d: ;

-include core/hooks.c.d

core/IPAddress.cpp.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/IPAddress.cpp core/IPAddress.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/IPAddress.cpp.d: ;

-include core/IPAddress.cpp.d

core/main.cpp.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/main.cpp core/main.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/main.cpp.d: ;

-include core/main.cpp.d

core/new.cpp.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/new.cpp core/new.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/new.cpp.d: ;

-include core/new.cpp.d

core/PluggableUSB.cpp.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/PluggableUSB.cpp core/PluggableUSB.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/PluggableUSB.cpp.d: ;

-include core/PluggableUSB.cpp.d

core/Print.cpp.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/Print.cpp core/Print.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Print.cpp.d: ;

-include core/Print.cpp.d

core/Stream.cpp.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/Stream.cpp core/Stream.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Stream.cpp.d: ;

-include core/Stream.cpp.d

core/Tone.cpp.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/Tone.cpp core/Tone.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Tone.cpp.d: ;

-include core/Tone.cpp.d

core/USBCore.cpp.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/USBCore.cpp core/USBCore.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/USBCore.cpp.d: ;

-include core/USBCore.cpp.d

core/WInterrupts.c.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/WInterrupts.c core/WInterrupts.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/WInterrupts.c.d: ;

-include core/WInterrupts.c.d

core/wiring.c.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/wiring.c core/wiring.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring.c.d: ;

-include core/wiring.c.d

core/wiring_analog.c.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/wiring_analog.c core/wiring_analog.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_analog.c.d: ;

-include core/wiring_analog.c.d

core/wiring_digital.c.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/wiring_digital.c core/wiring_digital.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_digital.c.d: ;

-include core/wiring_digital.c.d

core/wiring_pulse.c.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/wiring_pulse.c core/wiring_pulse.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_pulse.c.d: ;

-include core/wiring_pulse.c.d

core/wiring_pulse.S.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/wiring_pulse.S
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -x assembler-with-cpp -flto -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/wiring_shift.c.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/wiring_shift.c core/wiring_shift.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_shift.c.d: ;

-include core/wiring_shift.c.d

core/WMath.cpp.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/WMath.cpp core/WMath.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/WMath.cpp.d: ;

-include core/WMath.cpp.d

core/WString.cpp.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/WString.cpp core/WString.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/WString.cpp.d: ;

-include core/WString.cpp.d



libraries/Adafruit_NeoPixel/1.1.6/Adafruit_NeoPixel.cpp.o: C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6/Adafruit_NeoPixel.cpp libraries/Adafruit_NeoPixel/1.1.6/Adafruit_NeoPixel.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/Adafruit_NeoPixel/1.1.6/Adafruit_NeoPixel.cpp.d: ;

-include libraries/Adafruit_NeoPixel/1.1.6/Adafruit_NeoPixel.cpp.d

libraries/Adafruit_NeoPixel/1.1.6/esp8266.c.o: C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6/esp8266.c libraries/Adafruit_NeoPixel/1.1.6/esp8266.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/Adafruit_NeoPixel/1.1.6/esp8266.c.d: ;

-include libraries/Adafruit_NeoPixel/1.1.6/esp8266.c.d

libraries/Wire/src/utility/twi.c.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src/utility/twi.c libraries/Wire/src/utility/twi.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/Wire/src/utility/twi.c.d: ;

-include libraries/Wire/src/utility/twi.c.d

libraries/Wire/src/Wire.cpp.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src/Wire.cpp libraries/Wire/src/Wire.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/Wire/src/Wire.cpp.d: ;

-include libraries/Wire/src/Wire.cpp.d

libraries/IRremote/2.2.3/esp32.cpp.o: C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3/esp32.cpp libraries/IRremote/2.2.3/esp32.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/IRremote/2.2.3/esp32.cpp.d: ;

-include libraries/IRremote/2.2.3/esp32.cpp.d

libraries/IRremote/2.2.3/irPronto.cpp.o: C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3/irPronto.cpp libraries/IRremote/2.2.3/irPronto.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/IRremote/2.2.3/irPronto.cpp.d: ;

-include libraries/IRremote/2.2.3/irPronto.cpp.d

libraries/IRremote/2.2.3/irRecv.cpp.o: C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3/irRecv.cpp libraries/IRremote/2.2.3/irRecv.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/IRremote/2.2.3/irRecv.cpp.d: ;

-include libraries/IRremote/2.2.3/irRecv.cpp.d

libraries/IRremote/2.2.3/IRremote.cpp.o: C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3/IRremote.cpp libraries/IRremote/2.2.3/IRremote.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/IRremote/2.2.3/IRremote.cpp.d: ;

-include libraries/IRremote/2.2.3/IRremote.cpp.d

libraries/IRremote/2.2.3/irSend.cpp.o: C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3/irSend.cpp libraries/IRremote/2.2.3/irSend.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/IRremote/2.2.3/irSend.cpp.d: ;

-include libraries/IRremote/2.2.3/irSend.cpp.d

libraries/IRremote/2.2.3/ir_Aiwa.cpp.o: C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3/ir_Aiwa.cpp libraries/IRremote/2.2.3/ir_Aiwa.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/IRremote/2.2.3/ir_Aiwa.cpp.d: ;

-include libraries/IRremote/2.2.3/ir_Aiwa.cpp.d

libraries/IRremote/2.2.3/ir_Denon.cpp.o: C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3/ir_Denon.cpp libraries/IRremote/2.2.3/ir_Denon.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/IRremote/2.2.3/ir_Denon.cpp.d: ;

-include libraries/IRremote/2.2.3/ir_Denon.cpp.d

libraries/IRremote/2.2.3/ir_Dish.cpp.o: C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3/ir_Dish.cpp libraries/IRremote/2.2.3/ir_Dish.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/IRremote/2.2.3/ir_Dish.cpp.d: ;

-include libraries/IRremote/2.2.3/ir_Dish.cpp.d

libraries/IRremote/2.2.3/ir_JVC.cpp.o: C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3/ir_JVC.cpp libraries/IRremote/2.2.3/ir_JVC.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/IRremote/2.2.3/ir_JVC.cpp.d: ;

-include libraries/IRremote/2.2.3/ir_JVC.cpp.d

libraries/IRremote/2.2.3/ir_Lego_PF.cpp.o: C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3/ir_Lego_PF.cpp libraries/IRremote/2.2.3/ir_Lego_PF.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/IRremote/2.2.3/ir_Lego_PF.cpp.d: ;

-include libraries/IRremote/2.2.3/ir_Lego_PF.cpp.d

libraries/IRremote/2.2.3/ir_LG.cpp.o: C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3/ir_LG.cpp libraries/IRremote/2.2.3/ir_LG.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/IRremote/2.2.3/ir_LG.cpp.d: ;

-include libraries/IRremote/2.2.3/ir_LG.cpp.d

libraries/IRremote/2.2.3/ir_Mitsubishi.cpp.o: C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3/ir_Mitsubishi.cpp libraries/IRremote/2.2.3/ir_Mitsubishi.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/IRremote/2.2.3/ir_Mitsubishi.cpp.d: ;

-include libraries/IRremote/2.2.3/ir_Mitsubishi.cpp.d

libraries/IRremote/2.2.3/ir_NEC.cpp.o: C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3/ir_NEC.cpp libraries/IRremote/2.2.3/ir_NEC.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/IRremote/2.2.3/ir_NEC.cpp.d: ;

-include libraries/IRremote/2.2.3/ir_NEC.cpp.d

libraries/IRremote/2.2.3/ir_Panasonic.cpp.o: C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3/ir_Panasonic.cpp libraries/IRremote/2.2.3/ir_Panasonic.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/IRremote/2.2.3/ir_Panasonic.cpp.d: ;

-include libraries/IRremote/2.2.3/ir_Panasonic.cpp.d

libraries/IRremote/2.2.3/ir_RC5_RC6.cpp.o: C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3/ir_RC5_RC6.cpp libraries/IRremote/2.2.3/ir_RC5_RC6.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/IRremote/2.2.3/ir_RC5_RC6.cpp.d: ;

-include libraries/IRremote/2.2.3/ir_RC5_RC6.cpp.d

libraries/IRremote/2.2.3/ir_Samsung.cpp.o: C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3/ir_Samsung.cpp libraries/IRremote/2.2.3/ir_Samsung.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/IRremote/2.2.3/ir_Samsung.cpp.d: ;

-include libraries/IRremote/2.2.3/ir_Samsung.cpp.d

libraries/IRremote/2.2.3/ir_Sanyo.cpp.o: C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3/ir_Sanyo.cpp libraries/IRremote/2.2.3/ir_Sanyo.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/IRremote/2.2.3/ir_Sanyo.cpp.d: ;

-include libraries/IRremote/2.2.3/ir_Sanyo.cpp.d

libraries/IRremote/2.2.3/ir_Sharp.cpp.o: C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3/ir_Sharp.cpp libraries/IRremote/2.2.3/ir_Sharp.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/IRremote/2.2.3/ir_Sharp.cpp.d: ;

-include libraries/IRremote/2.2.3/ir_Sharp.cpp.d

libraries/IRremote/2.2.3/ir_Sony.cpp.o: C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3/ir_Sony.cpp libraries/IRremote/2.2.3/ir_Sony.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/IRremote/2.2.3/ir_Sony.cpp.d: ;

-include libraries/IRremote/2.2.3/ir_Sony.cpp.d

libraries/IRremote/2.2.3/ir_Template.cpp.o: C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3/ir_Template.cpp libraries/IRremote/2.2.3/ir_Template.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/IRremote/2.2.3/ir_Template.cpp.d: ;

-include libraries/IRremote/2.2.3/ir_Template.cpp.d

libraries/IRremote/2.2.3/ir_Whynter.cpp.o: C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3/ir_Whynter.cpp libraries/IRremote/2.2.3/ir_Whynter.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/IRremote/2.2.3/ir_Whynter.cpp.d: ;

-include libraries/IRremote/2.2.3/ir_Whynter.cpp.d

libraries/IRremote/2.2.3/sam.cpp.o: C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3/sam.cpp libraries/IRremote/2.2.3/sam.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/IRremote/2.2.3/sam.cpp.d: ;

-include libraries/IRremote/2.2.3/sam.cpp.d

libraries/SPI/src/SPI.cpp.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src/SPI.cpp libraries/SPI/src/SPI.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/SPI/src/SPI.cpp.d: ;

-include libraries/SPI/src/SPI.cpp.d

libraries/HID/src/HID.cpp.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src/HID.cpp libraries/HID/src/HID.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/HID/src/HID.cpp.d: ;

-include libraries/HID/src/HID.cpp.d

libraries/SoftwareSerial/src/SoftwareSerial.cpp.o: C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src/SoftwareSerial.cpp libraries/SoftwareSerial/src/SoftwareSerial.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Kenny/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Kenny/.arduinocdt/libraries/Adafruit_NeoPixel/1.1.6" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -I"C:/Users/Kenny/.arduinocdt/libraries/IRremote/2.2.3" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/HID/src" -I"C:/Users/Kenny/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/SoftwareSerial/src/SoftwareSerial.cpp.d: ;

-include libraries/SoftwareSerial/src/SoftwareSerial.cpp.d

