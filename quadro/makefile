# USED TOOLS #
PROJ_NAME = main
CC = g++

# SOURCES #
SRC = $(wildcard src/*.cpp)
OBJ += $(addprefix obj/,$(notdir $(SRC:.cpp=.o)))

CFLAGS  = -g -Wall 
#CFLAGS  = -D FAST
LDFLAGS =-lxerces-c -L lib -lcommand4rotate -lcommand4fly -ldl

INC += -Iinc 


$(PROJ_NAME) : $(OBJ)
	@echo 
	@echo -e "\033[35mGENERATE \033[32;5;148m$@\033[39m"
	$(CC) $(CFLAGS) $(OBJ) -o $(PROJ_NAME) $(LDFLAGS)

./obj/%.o : ./src/%.cpp
	@echo 
	@echo -e "\033[35mCOMPILING LIB \033[32;5;148m$@\033[39m"
	$(CC) -c $(INC) $(CFLAGS) $< -o $@


all : clean $(PROJ_NAME)
	./$(PROJ_NAME)
doc:
	make -C dox/	

clean :
	rm -rf ./obj/*
	rm -rf $(PROJ_NAME)	
	rm -rf src/*~
	rm -rf src/.*swp

warning: clean
	@echo -e "\033[33;5;148m ############# WARNINGS #############"
	@make 2>&1 |grep warning 
	@echo -e "\033[33;5;148m ############# \WARNINGS #############"

error: clean
	@echo -e "\033[31;5;148m ############# ERRORS #############"
	@make 2>&1 |grep error 
	@echo -e "\033[31;5;148m ############# \ERRORS #############"

