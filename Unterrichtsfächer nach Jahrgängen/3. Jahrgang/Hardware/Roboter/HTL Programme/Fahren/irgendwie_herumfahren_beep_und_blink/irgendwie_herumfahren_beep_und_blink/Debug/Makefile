################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../irgendwie_herumfahren_beep_und_blink.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
irgendwie_herumfahren_beep_und_blink.o


OBJS_AS_ARGS +=  \
irgendwie_herumfahren_beep_und_blink.o


C_DEPS +=  \
irgendwie_herumfahren_beep_und_blink.d


C_DEPS_AS_ARGS +=  \
irgendwie_herumfahren_beep_und_blink.d


OUTPUT_FILE_PATH +=irgendwie_herumfahren_beep_und_blink.elf

OUTPUT_FILE_PATH_AS_ARGS +=irgendwie_herumfahren_beep_und_blink.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

# AVR32/GNU C Compiler



./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : (AVR_8_bit_GNU_Toolchain_3.4.0_663) 4.6.2
	$(QUOTE)C:\Programme\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.0.65\AVRToolchain\bin\avr-gcc.exe$(QUOTE) -funsigned-char -funsigned-bitfields -O1 -fpack-struct -fshort-enums -g2 -Wall -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -mmcu=atmega32u4   -o"$@" "$<" 
	@echo Finished building: $<



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : (AVR_8_bit_GNU_Toolchain_3.4.0_663) 4.6.2
	$(QUOTE)C:\Programme\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.0.65\AVRToolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="irgendwie_herumfahren_beep_und_blink.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group  -mmcu=atmega32u4  
	@echo Finished building target: $@
	"C:\Programme\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.0.65\AVRToolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  "irgendwie_herumfahren_beep_und_blink.elf" "irgendwie_herumfahren_beep_und_blink.hex"
	"C:\Programme\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.0.65\AVRToolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "irgendwie_herumfahren_beep_und_blink.elf" "irgendwie_herumfahren_beep_und_blink.eep" || exit 0
	"C:\Programme\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.0.65\AVRToolchain\bin\avr-objdump.exe" -h -S "irgendwie_herumfahren_beep_und_blink.elf" > "irgendwie_herumfahren_beep_und_blink.lss"
	"C:\Programme\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.0.65\AVRToolchain\bin\avr-size.exe" "irgendwie_herumfahren_beep_und_blink.elf"
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS)$(C_DEPS_AS_ARGS) $(EXECUTABLES) 
	rm -rf "irgendwie_herumfahren_beep_und_blink.elf" "irgendwie_herumfahren_beep_und_blink.a" "irgendwie_herumfahren_beep_und_blink.hex" "irgendwie_herumfahren_beep_und_blink.lss" "irgendwie_herumfahren_beep_und_blink.eep" "irgendwie_herumfahren_beep_und_blink.map"
	