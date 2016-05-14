################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Edge.cpp \
../EdgeWeightedGraph.cpp \
../IndexMinPQ.cpp \
../KruskalMST.cpp \
../LazyPrimMST.cpp \
../PrimMST.cpp \
../QuickUnionPathCompressionUF.cpp \
../main.cpp 

OBJS += \
./Edge.o \
./EdgeWeightedGraph.o \
./IndexMinPQ.o \
./KruskalMST.o \
./LazyPrimMST.o \
./PrimMST.o \
./QuickUnionPathCompressionUF.o \
./main.o 

CPP_DEPS += \
./Edge.d \
./EdgeWeightedGraph.d \
./IndexMinPQ.d \
./KruskalMST.d \
./LazyPrimMST.d \
./PrimMST.d \
./QuickUnionPathCompressionUF.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


