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
sensores_posicao.lss \

FLASH_IMAGE += \
sensores_posicao.hex \

EEPROM_IMAGE += \
sensores_posicao.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: sensores_posicao.elf secondary-outputs

# Tool invocations
sensores_posicao.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,sensores_posicao.map -mmcu=atmega328p -o "sensores_posicao.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

sensores_posicao.lss: sensores_posicao.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S sensores_posicao.elf  >"sensores_posicao.lss"
	@echo 'Finished building: $@'
	@echo ' '

sensores_posicao.hex: sensores_posicao.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex sensores_posicao.elf  "sensores_posicao.hex"
	@echo 'Finished building: $@'
	@echo ' '

sensores_posicao.eep: sensores_posicao.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex sensores_posicao.elf  "sensores_posicao.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: sensores_posicao.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p sensores_posicao.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) sensores_posicao.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
