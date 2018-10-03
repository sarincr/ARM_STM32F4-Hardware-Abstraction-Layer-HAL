################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/STM32F4xx-Nucleo/stm32f4xx_nucleo.c 

OBJS += \
./Utilities/STM32F4xx-Nucleo/stm32f4xx_nucleo.o 

C_DEPS += \
./Utilities/STM32F4xx-Nucleo/stm32f4xx_nucleo.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/STM32F4xx-Nucleo/%.o: ../Utilities/STM32F4xx-Nucleo/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -DSTM32F446xx -DUSE_HAL_DRIVER -I"/home/angicia/Work Lab/Workbench/HAL/01.GPIO_Out/03.GPIO_Function/HAL_Driver/Inc/Legacy" -I"/home/angicia/Work Lab/Workbench/HAL/01.GPIO_Out/03.GPIO_Function/Utilities/STM32F4xx-Nucleo" -I"/home/angicia/Work Lab/Workbench/HAL/01.GPIO_Out/03.GPIO_Function/inc" -I"/home/angicia/Work Lab/Workbench/HAL/01.GPIO_Out/03.GPIO_Function/CMSIS/device" -I"/home/angicia/Work Lab/Workbench/HAL/01.GPIO_Out/03.GPIO_Function/CMSIS/core" -I"/home/angicia/Work Lab/Workbench/HAL/01.GPIO_Out/03.GPIO_Function/HAL_Driver/Inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

