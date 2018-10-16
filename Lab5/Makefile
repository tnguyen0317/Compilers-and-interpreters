CC = g++
CFLAGS += -Wall -std=c99 -g
OBJ = lexer.o symbol.o error.o treenode.o
SRC = symbol.cpp error.cpp treenode.cpp


29: 29.tab.o 29.tab.hpp $(OBJ)
	g++ -o 29 29.tab.o $(OBJ)

29.tab.cpp 29.tab.hpp: 29.ypp
	bison -d 29.ypp

lexer.o: lexer.cpp global.h
	g++ -Wall -c lexer.cpp

treenode.o: treenode.cpp treenode.h
	g++ -c treenode.cpp

symbol.o: 	symbol.cpp global.h
	g++ -Wall -c symbol.cpp

init.o: 	init.cpp global.h
	g++ -Wall -c init.cpp

error.o: 	error.cpp global.h
	g++ -Wall -c error.cpp

clean:
	$(RM) 29 29.tab.o 29.tab.cpp 29.tab.hpp lex.yy.o lex.yy.cpp
