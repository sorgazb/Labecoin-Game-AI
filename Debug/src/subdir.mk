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


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Coordenada.d ./src/Coordenada.o ./src/ESEstocastico.d ./src/ESEstocastico.o ./src/EscaladaSimple.d ./src/EscaladaSimple.o ./src/Fichero.d ./src/Fichero.o ./src/FuncionDistancia.d ./src/FuncionDistancia.o ./src/FuncionRentabilidad.d ./src/FuncionRentabilidad.o ./src/IASI.d ./src/IASI.o ./src/MaximaPendiente.d ./src/MaximaPendiente.o ./src/Moneda.d ./src/Moneda.o ./src/Tablero.d ./src/Tablero.o ./src/vectorMonedas.d ./src/vectorMonedas.o

.PHONY: clean-src

