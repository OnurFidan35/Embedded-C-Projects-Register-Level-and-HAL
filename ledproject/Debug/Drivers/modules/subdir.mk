################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/modules/buttondriver.c \
../Drivers/modules/leddriver.c 

OBJS += \
./Drivers/modules/buttondriver.o \
./Drivers/modules/leddriver.o 

C_DEPS += \
./Drivers/modules/buttondriver.d \
./Drivers/modules/leddriver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/modules/%.o Drivers/modules/%.su Drivers/modules/%.cyclo: ../Drivers/modules/%.c Drivers/modules/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Drivers/modules -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-modules

clean-Drivers-2f-modules:
	-$(RM) ./Drivers/modules/buttondriver.cyclo ./Drivers/modules/buttondriver.d ./Drivers/modules/buttondriver.o ./Drivers/modules/buttondriver.su ./Drivers/modules/leddriver.cyclo ./Drivers/modules/leddriver.d ./Drivers/modules/leddriver.o ./Drivers/modules/leddriver.su

.PHONY: clean-Drivers-2f-modules

