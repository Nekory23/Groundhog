##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

## Var def ##
SHELL		=	/bin/sh
CC			=	gcc
CPP			=	g++
RM			=	rm -f
#############

## Sources ##
MAIN		=	src/Main.cpp

BIN_SRC		=	src/Start.cpp		\
				src/Error.cpp		\
				src/Groundhog.cpp	\

TEST_SRC	=	tests/TestError.cpp			\
				tests/TestCleanInput.cpp	\
				tests/TestDisplay.cpp		\
				tests/TestInput.cpp

INC			=	-I./include/
#############

##	Obj	   ##
MAIN_OBJ	=	$(MAIN:.cpp=.o)
SRC_OBJ		=	$(BIN_SRC:.cpp=.o)
TEST_OBJ	=	$(TEST_SRC:.cpp=.o)
#############

##	Flags  ##
CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	$(INC)
LDFLAGS		=	-lm
#############

##	Names  ##
BIN			=   groundhog
TEST_BIN	=	unit_tests
#############

##	Rules  ##
all:	$(MAIN_OBJ) $(SRC_OBJ)
	@$(CPP) -o $(BIN) $(MAIN_OBJ) $(SRC_OBJ) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
	@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(BIN) | tr ' ' '.'

# Debug
debug:	fclean
debug:	CFLAGS += -g3 -DDEBUG
debug:	all

# Unit Test
tests_run:	fclean
tests_run:	CFLAGS += --coverage
tests_run:	LDFLAGS += -lcriterion -DUNIT_TEST
tests_run:	$(SRC_OBJ) $(TEST_OBJ)
	$(CPP) -o $(TEST_BIN) $(BIN_SRC) $(TEST_SRC) $(LDFLAGS) $(CFLAGS) $(CPPFLAGS)
	./$(TEST_BIN)

# Coverage
coverage:
	gcovr -b --exclude-directories tests
	gcovr -r . --exclude-directories tests

# Clear
clean:
	@$(RM) $(MAIN_OBJ)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(MAIN_OBJ) | tr ' ' '.'
	@$(RM) $(SRC_OBJ)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(SRC_OBJ) | tr ' ' '.'
	@$(RM) $(TEST_OBJ)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(TEST_OBJ) | tr ' ' '.'

fclean: clean
	@$(RM) $(BIN)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(BIN) | tr ' ' '.'
	@$(RM) $(TEST_BIN)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(TEST_BIN) | tr ' ' '.'
	@$(RM) *.gc*

# re
re : fclean all

# PHONY
.PHONY: all debug tests_run coverage clean fclean re