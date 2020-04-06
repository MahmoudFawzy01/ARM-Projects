################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/CLCD_program.c \
../src/DELAY_program.c \
../src/DIO_program.c \
../src/FLASH_PROGRAM.c \
../src/GSM_program.c \
../src/HEX_ParserPhases.c \
../src/RCC_program.c \
../src/USART_Prog.c \
../src/app.c 

OBJS += \
./src/CLCD_program.o \
./src/DELAY_program.o \
./src/DIO_program.o \
./src/FLASH_PROGRAM.o \
./src/GSM_program.o \
./src/HEX_ParserPhases.o \
./src/RCC_program.o \
./src/USART_Prog.o \
./src/app.o 

C_DEPS += \
./src/CLCD_program.d \
./src/DELAY_program.d \
./src/DIO_program.d \
./src/FLASH_PROGRAM.d \
./src/GSM_program.d \
./src/HEX_ParserPhases.d \
./src/RCC_program.d \
./src/USART_Prog.d \
./src/app.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


