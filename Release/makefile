################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include arduino/variant/subdir.mk
-include arduino/core/avr/subdir.mk
-include arduino/core/USB/subdir.mk
-include arduino/core/subdir.mk
-include Libraries/DueTimer/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
C:/Users/jon_000/Git/ALFRED_TEST/Release/arduino.ar \

ELF += \
ALFRED_TEST.elf \

EEP += \
ALFRED_TEST.eep \

FLASH_IMAGE += \
ALFRED_TEST.bin \


# All Target
all: ALFRED_TEST

# Tool invocations
ALFRED_TEST: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"C:/Arduino/hardware/tools/g++_arm_none_eabi/bin/arm-none-eabi-size" -A "C:/Users/jon_000/Git/ALFRED_TEST/Release/ALFRED_TEST.elf"
	@echo 'Finished building target: $@'
	@echo ' '

C:/Users/jon_000/Git/ALFRED_TEST/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"C:/Arduino/hardware/tools/g++_arm_none_eabi/bin/arm-none-eabi-ar" rcs "C:/Users/jon_000/Git/ALFRED_TEST/Release/arduino.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

ALFRED_TEST.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"C:/Arduino/hardware/tools/g++_arm_none_eabi/bin/arm-none-eabi-g++" -Os -Wl,--gc-sections -mcpu=cortex-m3 "-T/C:/Arduino/hardware/arduino/sam/variants/arduino_due_x/linker_scripts/gcc/flash.ld" "-Wl,-Map,C:/Users/jon_000/Git/ALFRED_TEST/Release/ALFRED_TEST.map" -o "C:/Users/jon_000/Git/ALFRED_TEST/Release/ALFRED_TEST.elf" "-LC:/Users/jon_000/Git/ALFRED_TEST/Release" -lm -lgcc -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group "C:/Users/jon_000/Git/ALFRED_TEST/Release/arduino/syscalls_sam3.c.o"   $(LINK_OBJ) $(AR)  "/C:/Arduino/hardware/arduino/sam/variants/arduino_due_x/libsam_sam3x8e_gcc_rel.a" "C:/Users/jon_000/Git/ALFRED_TEST/Release/arduino.ar" -Wl,--end-group
	@echo 'Finished building: $@'
	@echo ' '

ALFRED_TEST.eep: $(ELF)
	@echo 'Create eeprom image'
	${A.RECIPE.OBJCOPY.EEP.PATTERN}
	@echo 'Finished building: $@'
	@echo ' '

ALFRED_TEST.bin: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"C:/Arduino/hardware/tools/g++_arm_none_eabi/bin/arm-none-eabi-objcopy" -O binary "C:/Users/jon_000/Git/ALFRED_TEST/Release/ALFRED_TEST.elf" "C:/Users/jon_000/Git/ALFRED_TEST/Release/ALFRED_TEST.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELF)$(C++_DEPS)$(AR)$(C_DEPS)$(CC_DEPS)$(FLASH_IMAGE)$(AR_OBJ)$(CPP_DEPS)$(LINK_OBJ)$(EEP)$(CXX_DEPS)$(C_UPPER_DEPS)$(SIZEDUMMY) ALFRED_TEST
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
