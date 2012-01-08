################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/devices/Counter.c \
../drivers/devices/Multiplexer.c \
../drivers/devices/SDCard.c \
../drivers/devices/SPIDevice.c \
../drivers/devices/Watchdog.c 

OBJS += \
./drivers/devices/Counter.obj \
./drivers/devices/Multiplexer.obj \
./drivers/devices/SDCard.obj \
./drivers/devices/SPIDevice.obj \
./drivers/devices/Watchdog.obj 

C_DEPS += \
./drivers/devices/Counter.pp \
./drivers/devices/Multiplexer.pp \
./drivers/devices/SDCard.pp \
./drivers/devices/SPIDevice.pp \
./drivers/devices/Watchdog.pp 

OBJS__QTD += \
".\drivers\devices\Counter.obj" \
".\drivers\devices\Multiplexer.obj" \
".\drivers\devices\SDCard.obj" \
".\drivers\devices\SPIDevice.obj" \
".\drivers\devices\Watchdog.obj" 

C_DEPS__QTD += \
".\drivers\devices\Counter.pp" \
".\drivers\devices\Multiplexer.pp" \
".\drivers\devices\SDCard.pp" \
".\drivers\devices\SPIDevice.pp" \
".\drivers\devices\Watchdog.pp" 

C_SRCS_QUOTED += \
"../drivers/devices/Counter.c" \
"../drivers/devices/Multiplexer.c" \
"../drivers/devices/SDCard.c" \
"../drivers/devices/SPIDevice.c" \
"../drivers/devices/Watchdog.c" 


# Each subdirectory must supply rules for building sources it contributes
drivers/devices/Counter.obj: ../drivers/devices/Counter.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --define=__MSP430FG4619__ --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Users/Kane/Project-Cheesecake/source/application" --include_path="C:/Users/Kane/Project-Cheesecake/source/test application" --include_path="C:/Users/Kane/Project-Cheesecake/source" --include_path="C:/Users/Kane/Project-Cheesecake/source/drivers" --include_path="C:/Users/Kane/Project-Cheesecake/source/drivers/devices" --include_path="C:/Users/Kane/Project-Cheesecake/source/system" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="drivers/devices/Counter.pp" --obj_directory="drivers/devices" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

drivers/devices/Multiplexer.obj: ../drivers/devices/Multiplexer.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --define=__MSP430FG4619__ --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Users/Kane/Project-Cheesecake/source/application" --include_path="C:/Users/Kane/Project-Cheesecake/source/test application" --include_path="C:/Users/Kane/Project-Cheesecake/source" --include_path="C:/Users/Kane/Project-Cheesecake/source/drivers" --include_path="C:/Users/Kane/Project-Cheesecake/source/drivers/devices" --include_path="C:/Users/Kane/Project-Cheesecake/source/system" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="drivers/devices/Multiplexer.pp" --obj_directory="drivers/devices" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

drivers/devices/SDCard.obj: ../drivers/devices/SDCard.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --define=__MSP430FG4619__ --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Users/Kane/Project-Cheesecake/source/application" --include_path="C:/Users/Kane/Project-Cheesecake/source/test application" --include_path="C:/Users/Kane/Project-Cheesecake/source" --include_path="C:/Users/Kane/Project-Cheesecake/source/drivers" --include_path="C:/Users/Kane/Project-Cheesecake/source/drivers/devices" --include_path="C:/Users/Kane/Project-Cheesecake/source/system" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="drivers/devices/SDCard.pp" --obj_directory="drivers/devices" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

drivers/devices/SPIDevice.obj: ../drivers/devices/SPIDevice.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --define=__MSP430FG4619__ --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Users/Kane/Project-Cheesecake/source/application" --include_path="C:/Users/Kane/Project-Cheesecake/source/test application" --include_path="C:/Users/Kane/Project-Cheesecake/source" --include_path="C:/Users/Kane/Project-Cheesecake/source/drivers" --include_path="C:/Users/Kane/Project-Cheesecake/source/drivers/devices" --include_path="C:/Users/Kane/Project-Cheesecake/source/system" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="drivers/devices/SPIDevice.pp" --obj_directory="drivers/devices" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

drivers/devices/Watchdog.obj: ../drivers/devices/Watchdog.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --define=__MSP430FG4619__ --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Users/Kane/Project-Cheesecake/source/application" --include_path="C:/Users/Kane/Project-Cheesecake/source/test application" --include_path="C:/Users/Kane/Project-Cheesecake/source" --include_path="C:/Users/Kane/Project-Cheesecake/source/drivers" --include_path="C:/Users/Kane/Project-Cheesecake/source/drivers/devices" --include_path="C:/Users/Kane/Project-Cheesecake/source/system" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="drivers/devices/Watchdog.pp" --obj_directory="drivers/devices" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


