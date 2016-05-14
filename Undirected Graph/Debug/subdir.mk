################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Bipartite.cpp \
../BreadthFirstPaths.cpp \
../CC.cpp \
../Cycle.cpp \
../DepthFirstPaths.cpp \
../DepthFirstSearch.cpp \
../Graph.cpp \
../Graph_test.cpp 

OBJS += \
./Bipartite.o \
./BreadthFirstPaths.o \
./CC.o \
./Cycle.o \
./DepthFirstPaths.o \
./DepthFirstSearch.o \
./Graph.o \
./Graph_test.o 

CPP_DEPS += \
./Bipartite.d \
./BreadthFirstPaths.d \
./CC.d \
./Cycle.d \
./DepthFirstPaths.d \
./DepthFirstSearch.d \
./Graph.d \
./Graph_test.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


