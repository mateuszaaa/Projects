# USED TOOLS #
PROJ_NAME = main
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
SIZE = arm-none-eabi-size
CC = arm-none-eabi-gcc
GDB = /usr/bin/arm-none-eabi-gdb

# DEBUGGING CONSTANS #
GDB_FLASH_SCRIPT = contrib/flash.gdb 
GDB_DEBUG_SCRIPT = contrib/debug.gdb 
GDB_RESET_SCRIPT = contrib/reset.gdb 
OPENOCD_START =  gnome-terminal -e "openocd -f /usr/share/openocd/scripts/interface/stlink-v2.cfg -f /usr/share/openocd/scripts/target/stm32f4x_stlink.cfg"
#OPENOCD_START =  gnome-terminal -e "openocd -f /usr/share/openocd/scripts/board/stm32f4discovery.cfg "
OPENOCD_STOP = killall openocd 
DEBUG = /usr/bin/nemiver DEBUG_FLAGS = --remote=localhost:3333 --gdb-binary=$(GDB) 
# SOURCES #
SRC = $(wildcard src/*.c)
OBJ += $(addprefix obj/,$(notdir $(SRC:.c=.o)))
OBJ += ./obj/startup_stm32f4xx.o 
SRC_ST = $(wildcard ./Libraries/STM32F4xx_StdPeriph_Driver/src/*.c)
OBJ_ST = $(SRC_ST:.c=.o)

# FLAGS #

CFLAGS  = -g -Wall -Wno-missing-braces -std=c99
CFLAGS += -mthumb -mcpu=cortex-m4
CFLAGS += -mfloat-abi=soft

INC += -Iinc -ILibraries/Device/STM32F4xx/Include/ -ILibraries/CMSIS/Include/
INC += -ILibraries/STM32F4xx_StdPeriph_Driver/inc
INC += -ILibraries/CMSIS/Include
INC += -ILibraries/Device/STM32F4xx/Include
INC += -Iinc

LDFLAGS = -Wl,-Map,$(PROJ_NAME).map -g -Tstm32f4_flash.ld

# STLIBS FLAGS#
LDFLAGS_ST += -DUSE_STDPERIPH_DRIVER -DUSE_STM32F4_DISCOVERY -DSTM32F4XX


$(PROJ_NAME).elf : $(OBJ_ST) $(OBJ)
	@echo 
	@echo -e "\033[35mGENERATE \033[32;5;148m$@\033[39m"
	$(CC) $(CFLAGS) $(OBJ) -o main.elf $(LDFLAGS)
#	$(CC) $(CFLAGS) $(OBJ) $(OBJ_ST) -o main.elf $(LDFLAGS)
	@echo 
	$(OBJCOPY) -O ihex $(PROJ_NAME).elf $(PROJ_NAME).hex
	$(OBJCOPY) -O binary $(PROJ_NAME).elf $(PROJ_NAME).bin
	$(SIZE) $(PROJ_NAME).elf

./Libraries/STM32F4xx_StdPeriph_Driver/src/%.o : ./Libraries/STM32F4xx_StdPeriph_Driver/src/%.c 
	@echo ""
	@echo -e "\033[35mCOMPILING ST LIB \033[32;5;148m$@\033[39m"
	$(CC) -c $(CFLAGS) $(LDFLAGS_ST) $(INC) $< -o $@  

./obj/%.o : ./src/%.c
	@echo 
	@echo -e "\033[35mCOMPILING LIB \033[32;5;148m$@\033[39m"
	@$(CC) -c $(INC) $(CFLAGS) $< -o $@
	@echo "$(CC) -c INC CFLAGS $< -o $@"

./obj/%.o : ./src/%.S
	@echo 
	@echo -e "\033[35mCOMPILING ASSEMBLER \033[32;5;148m$@\033[39m"
	@$(CC) -c $(INC) $(CFLAGS) $< -o $@
	@echo "$(CC) -c INC CFLAGS $< -o $@"

all : clean $(PROJ_NAME).elf

program : all
	$(OPENOCD_START)
	$(GDB) -x $(GDB_FLASH_SCRIPT) --batch $(PROJ_NAME).elf
	$(OPENOCD_STOP)

reset :
	$(OPENOCD_START)
	$(GDB) -x $(GDB_RESET_SCRIPT) --batch $(PROJ_NAME).elf
	$(OPENOCD_STOP)

debug : $(PROJ_NAME).elf
	$(OPENOCD_START)
	$(GDB) -x $(GDB_DEBUG_SCRIPT) --batch $(PROJ_NAME).elf
	$(DEBUG) $(DEBUG_FLAGS) $(PROJ_NAME).elf
	$(OPENOCD_STOP)

blink : $(PROJ_NAME).elf
	$(OPENOCD_START)
	cp test.elf main.elf
	$(GDB) -x $(GDB_FLASH_SCRIPT) --batch $(PROJ_NAME).elf
	rm main.elf
	$(OPENOCD_STOP)

debug2 : $(PROJ_NAME).elf
	$(OPENOCD_START)
	$(GDB) -x contrib/debug-gdb.gdb --batch $(PROJ_NAME).elf
	arm-none-eabi-gdb --eval-command="target remote localhost:3333" $(PROJ_NAME).elf
	$(OPENOCD_STOP)
usart: $(PROJ_NAME).elf 
	./contrib/stm32ld /dev/ttyUSB0 115200 $(PROJ_NAME).bin 1
start: 
	./contrib/stm32ld /dev/ttyUSB0 115200 0 1
clean :
	rm -rf ./obj/*
	rm -rf $(PROJ_NAME).*	
	rm -rf src/*~
	rm -rf src/.*swp
#	rm -rf ./Libraries/STM32F4xx_StdPeriph_Driver/src/*.o
warning: clean
	@echo -e "\033[33;5;148m ############# WARNINGS #############"
	@make 2>&1 |grep warning 
	@echo -e "\033[33;5;148m ############# \WARNINGS #############"

error: clean
	@echo -e "\033[31;5;148m ############# ERRORS #############"
	@make 2>&1 |grep error 
	@echo -e "\033[31;5;148m ############# \ERRORS #############"

__test__:
	@echo
	@echo "BIBLIOTEKI"
	@echo $(OBJ_ST)
	@echo

