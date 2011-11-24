################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/Drivers.c \
../drivers/DriversConfig.c 

OBJS += \
./drivers/Drivers.obj \
./drivers/DriversConfig.obj 

C_DEPS += \
./drivers/Drivers.pp \
./drivers/DriversConfig.pp 

OBJS__QTD += \
".\drivers\Drivers.obj" \
".\drivers\DriversConfig.obj" 

C_DEPS__QTD += \
".\drivers\Drivers.pp" \
".\drivers\DriversConfig.pp" 

C_SRCS_QUOTED += \
"../drivers/Drivers.c" \
"../drivers/DriversConfig.c" 


# Each subdirectory must supply rules for building sources it contributes
drivers/Drivers.obj: ../drivers/Drivers.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/Program Files/MSP430/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --define=__MSP430FG4619__ --include_path="D:/Program Files/MSP430/ccsv4/msp430/include" --include_path="D:/Program Files/MSP430/ccsv4/tools/compiler/msp430/include" --include_path="C:/Users/Kane/Project-Cheesecake/source/application" --include_path="C:/Users/Kane/Project-Cheesecake/source/drivers" --include_path="C:/Users/Kane/Project-Cheesecake/source/system" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="drivers/Drivers.pp" --obj_directory="drivers" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

drivers/DriversConfig.obj: ../drivers/DriversConfig.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/Program Files/MSP430/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --define=__MSP430FG4619__ --include_path="D:/Program Files/MSP430/ccsv4/msp430/include" --include_path="D:/Program Files/MSP430/ccsv4/tools/compiler/msp430/include" --include_path="C:/Users/Kane/Project-Cheesecake/source/application" --include_path="C:/Users/Kane/Project-Cheesecake/source/drivers" --include_path="C:/Users/Kane/Project-Cheesecake/source/system" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="drivers/DriversConfig.pp" --obj_directory="drivers" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


