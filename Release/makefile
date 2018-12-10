################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include lib/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
trab_final_sensores.lss \

FLASH_IMAGE += \
trab_final_sensores.hex \

EEPROM_IMAGE += \
trab_final_sensores.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: trab_final_sensores.elf secondary-outputs

# Tool invocations
trab_final_sensores.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,trab_final_sensores.map -mmcu=atmega328p -o "trab_final_sensores.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

trab_final_sensores.lss: trab_final_sensores.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S trab_final_sensores.elf  >"trab_final_sensores.lss"
	@echo 'Finished building: $@'
	@echo ' '

trab_final_sensores.hex: trab_final_sensores.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex trab_final_sensores.elf  "trab_final_sensores.hex"
	@echo 'Finished building: $@'
	@echo ' '

trab_final_sensores.eep: trab_final_sensores.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex trab_final_sensores.elf  "trab_final_sensores.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: trab_final_sensores.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p trab_final_sensores.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) trab_final_sensores.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
