################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/System.c \
../system/SystemConfig.c 

OBJS += \
./system/System.obj \
./system/SystemConfig.obj 

C_DEPS += \
./system/System.pp \
./system/SystemConfig.pp 

OBJS__QTD += \
".\system\System.obj" \
".\system\SystemConfig.obj" 

C_DEPS__QTD += \
".\system\System.pp" \
".\system\SystemConfig.pp" 

C_SRCS_QUOTED += \
"../system/System.c" \
"../system/SystemConfig.c" 


# Each subdirectory must supply rules for building sources it contributes
system/System.obj: ../system/System.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/Program Files/MSP430/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --define=__MSP430FG4619__ --include_path="D:/Program Files/MSP430/ccsv4/msp430/include" --include_path="D:/Program Files/MSP430/ccsv4/tools/compiler/msp430/include" --include_path="C:/Users/Kane/Project-Cheesecake/source/application" --include_path="C:/Users/Kane/Project-Cheesecake/source/test application" --include_path="C:/Users/Kane/Project-Cheesecake/source" --include_path="C:/Users/Kane/Project-Cheesecake/source/drivers" --include_path="C:/Users/Kane/Project-Cheesecake/source/drivers/devices" --include_path="C:/Users/Kane/Project-Cheesecake/source/system" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="system/System.pp" --obj_directory="system" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

system/SystemConfig.obj: ../system/SystemConfig.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/Program Files/MSP430/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --define=__MSP430FG4619__ --include_path="D:/Program Files/MSP430/ccsv4/msp430/include" --include_path="D:/Program Files/MSP430/ccsv4/tools/compiler/msp430/include" --include_path="C:/Users/Kane/Project-Cheesecake/source/application" --include_path="C:/Users/Kane/Project-Cheesecake/source/test application" --include_path="C:/Users/Kane/Project-Cheesecake/source" --include_path="C:/Users/Kane/Project-Cheesecake/source/drivers" --include_path="C:/Users/Kane/Project-Cheesecake/source/drivers/devices" --include_path="C:/Users/Kane/Project-Cheesecake/source/system" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="system/SystemConfig.pp" --obj_directory="system" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


