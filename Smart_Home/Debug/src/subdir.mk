################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Smart_Home.c \
../src/adc.c \
../src/buzzer.c \
../src/dc_motor.c \
../src/flame_sensor.c \
../src/gpio.c \
../src/lcd.c \
../src/ldr.c \
../src/led.c \
../src/lm35_sensor.c \
../src/pwm.c 

OBJS += \
./src/Smart_Home.o \
./src/adc.o \
./src/buzzer.o \
./src/dc_motor.o \
./src/flame_sensor.o \
./src/gpio.o \
./src/lcd.o \
./src/ldr.o \
./src/led.o \
./src/lm35_sensor.o \
./src/pwm.o 

C_DEPS += \
./src/Smart_Home.d \
./src/adc.d \
./src/buzzer.d \
./src/dc_motor.d \
./src/flame_sensor.d \
./src/gpio.d \
./src/lcd.d \
./src/ldr.d \
./src/led.d \
./src/lm35_sensor.d \
./src/pwm.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


