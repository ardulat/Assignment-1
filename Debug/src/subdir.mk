################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Anuar\ Maratkhan.c 

OBJS += \
./src/Anuar\ Maratkhan.o 

C_DEPS += \
./src/Anuar\ Maratkhan.d 


# Each subdirectory must supply rules for building sources it contributes
src/Anuar\ Maratkhan.o: ../src/Anuar\ Maratkhan.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Anuar Maratkhan.d" -MT"src/Anuar\ Maratkhan.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


