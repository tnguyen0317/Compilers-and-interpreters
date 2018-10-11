CC = gcc
CFLAGS += -Wall -std=c99 -g
OBJ = lexer.o symbol.o error.o treenode.o
SRC = lexer.cpp symbol.cpp error.cpp 


29: 29.tab.o 29.tab.hpp $(OBJ)
	gcc -o 29 29.tab.o $(OBJ)
	
29.tab.cpp 29.tab.hpp: 29.ypp
	bison -d 29.ypp
	
treenode.o: treenode.h
	gcc treenode.h

lexer.o: 	lexer.cpp global.h
	gcc -Wall -c lexer.cpp

symbol.o: 	symbol.cpp global.h
	gcc -Wall -c symbol.cpp

init.o: 	init.cpp global.h
	gcc -Wall -c init.cpp

error.o: 	error.cpp global.h
	gcc -Wall -c error.cpp

clean:
	$(RM) 29 29.tab.o 29.tab.cpp 29.tab.hpp lex.yy.o lex.yy.cpp
