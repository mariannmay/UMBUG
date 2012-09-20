################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../test\ application/TestApplication.c 

OBJS += \
./test\ application/TestApplication.obj 

C_DEPS += \
./test\ application/TestApplication.pp 

OBJS__QTD += \
".\test application\TestApplication.obj" 

C_DEPS__QTD += \
".\test application\TestApplication.pp" 

C_SRCS_QUOTED += \
"../test application/TestApplication.c" 


# Each subdirectory must supply rules for building sources it contributes
test\ application/TestApplication.obj: ../test\ application/TestApplication.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --define=__MSP430FG4619__ --define=__MSP430FG4618__ --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Users/Kane/Project-Cheesecake/source/application" --include_path="C:/Users/Kane/Project-Cheesecake/source/test application" --include_path="C:/Users/Kane/Project-Cheesecake/source" --include_path="C:/Users/Kane/Project-Cheesecake/source/drivers" --include_path="C:/Users/Kane/Project-Cheesecake/source/drivers/devices" --include_path="C:/Users/Kane/Project-Cheesecake/source/system" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="test application/TestApplication.pp" --obj_directory="test application" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


