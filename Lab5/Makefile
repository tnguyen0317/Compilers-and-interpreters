CC = g++
CFLAGS += -Wall -g
OBJ = lex.yy.o treenode.o symbol.o error.o
SRC = symbol.cpp treenode.cpp error.cpp


29: 29.tab.o 29.tab.hpp $(OBJ)
	g++ -o 29 29.tab.o $(OBJ)

29.tab.cpp 29.tab.hpp: 29.ypp
	bison -d 29.ypp

lex.yy.c: 29.l
	flex 29.l

treenode.o: treenode.cpp treenode.h
	g++ -c treenode.cpp

error.o: error.cpp global.h
	g++ -Wall -c error.cpp

symbol.o: symbol.cpp global.h
	g++ -Wall -c symbol.cpp

init.o: 	init.cpp global.h
	g++ -Wall -c init.cpp

clean:
	$(RM) 29 29.tab.o 29.tab.cpp 29.tab.hpp lex.yy.o lex.yy.cpp
