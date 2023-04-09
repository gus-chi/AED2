BIN = ./bin
INC = ./include
OBJ = ./obj
SRC = ./src
TESTS = ./tests

DEP = $(OBJ)/list.o
MODULES = $(INC)/list.c 
TEST_MODULES = $(INC)/Unity/unity.c $(INC)/list.c
BIN_PROGRAM = $(BIN)/main.x
BIN_TEST = $(BIN)/test.t
all:	link
#all:	compile link

#compile:	$(DEP)

link: $(BIN_PROGRAM)

test:	$(BIN_TEST)
	$<
#$(OBJ)/%.o:	$(SRC)/%.c $(INC)/%.h
#	gcc -c $< -I $(INC) -o $@

$(BIN)/%.x: $(SRC)/%.c $(MODULES)
	gcc -g $< $(MODULES) -I $(INC) -o $@ 

$(BIN)/%.t: $(TESTS)/$(SRC)/%.c $(TEST_MODULES)
	gcc -g $< $(TEST_MODULES) -I $(INC) -I $(INC)/Unity -o $@



#$(BIN)/%.x: $(SRC)/%.c $(DEP)
#	gcc -g $< $(DEP) -I $(INC) -o $@ 

clear:
	rm -f $(BIN)/* $(OBJ)/*

debug:	$(BIN_PROGRAM)
	gdb $<

run:	$(BIN_PROGRAM)
	$<
