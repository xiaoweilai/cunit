INC=-I/usr/local/include
LIB=-L/usr/local/lib

all: MainModule.c TestMainModule.c CUnitRunTest.c
	gcc $^ -o test $(INC) $(LIB) -lcunit -lcurses -static
clean:
	rm -rf test

