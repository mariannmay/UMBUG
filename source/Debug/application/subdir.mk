################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../application/Application.c \
../application/ApplicationConfig.c 

OBJS += \
./application/Application.obj \
./application/ApplicationConfig.obj 

C_DEPS += \
./application/Application.pp \
./application/ApplicationConfig.pp 

OBJS__QTD += \
".\application\Application.obj" \
".\application\ApplicationConfig.obj" 

C_DEPS__QTD += \
".\application\Application.pp" \
".\application\ApplicationConfig.pp" 

C_SRCS_QUOTED += \
"../application/Application.c" \
"../application/ApplicationConfig.c" 


# Each subdirectory must supply rules for building sources it contributes
application/Application.obj: ../application/Application.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --define=__MSP430FG4619__ --define=__MSP430FG4618__ --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Users/Kane/Project-Cheesecake/source/application" --include_path="C:/Users/Kane/Project-Cheesecake/source/test application" --include_path="C:/Users/Kane/Project-Cheesecake/source" --include_path="C:/Users/Kane/Project-Cheesecake/source/drivers" --include_path="C:/Users/Kane/Project-Cheesecake/source/drivers/devices" --include_path="C:/Users/Kane/Project-Cheesecake/source/system" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="application/Application.pp" --obj_directory="application" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

application/ApplicationConfig.obj: ../application/ApplicationConfig.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --define=__MSP430FG4619__ --define=__MSP430FG4618__ --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Users/Kane/Project-Cheesecake/source/application" --include_path="C:/Users/Kane/Project-Cheesecake/source/test application" --include_path="C:/Users/Kane/Project-Cheesecake/source" --include_path="C:/Users/Kane/Project-Cheesecake/source/drivers" --include_path="C:/Users/Kane/Project-Cheesecake/source/drivers/devices" --include_path="C:/Users/Kane/Project-Cheesecake/source/system" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="application/ApplicationConfig.pp" --obj_directory="application" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


