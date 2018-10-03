################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32f446xx.s 

OBJS += \
./startup/startup_stm32f446xx.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -I"/home/angicia/Work Lab/Workbench/HAL/01.GPIO_Out/STM_HAL_Base/HAL_Driver/Inc/Legacy" -I"/home/angicia/Work Lab/Workbench/HAL/01.GPIO_Out/STM_HAL_Base/Utilities/STM32F4xx-Nucleo" -I"/home/angicia/Work Lab/Workbench/HAL/01.GPIO_Out/STM_HAL_Base/inc" -I"/home/angicia/Work Lab/Workbench/HAL/01.GPIO_Out/STM_HAL_Base/CMSIS/device" -I"/home/angicia/Work Lab/Workbench/HAL/01.GPIO_Out/STM_HAL_Base/CMSIS/core" -I"/home/angicia/Work Lab/Workbench/HAL/01.GPIO_Out/STM_HAL_Base/HAL_Driver/Inc" -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


