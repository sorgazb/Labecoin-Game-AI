################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Coordenada.cpp \
../src/ESEstocastico.cpp \
../src/EscaladaSimple.cpp \
../src/Fichero.cpp \
../src/FuncionDistancia.cpp \
../src/FuncionRentabilidad.cpp \
../src/IASI.cpp \
../src/MaximaPendiente.cpp \
../src/Moneda.cpp \
../src/Tablero.cpp \
../src/vectorMonedas.cpp 

OBJS += \
./src/Coordenada.o \
./src/ESEstocastico.o \
./src/EscaladaSimple.o \
./src/Fichero.o \
./src/FuncionDistancia.o \
./src/FuncionRentabilidad.o \
./src/IASI.o \
./src/MaximaPendiente.o \
./src/Moneda.o \
./src/Tablero.o \
./src/vectorMonedas.o 

CPP_DEPS += \
./src/Coordenada.d \
./src/ESEstocastico.d \
./src/EscaladaSimple.d \
./src/Fichero.d \
./src/FuncionDistancia.d \
./src/FuncionRentabilidad.d \
./src/IASI.d \
./src/MaximaPendiente.d \
./src/Moneda.d \
./src/Tablero.d \
./src/vectorMonedas.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


