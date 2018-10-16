CC = gcc
CFLAGS += -Wall -std=c99 -g
OBJ = lexer.o symbol.o error.o
SRC = lexer.c symbol.c error.c


29: 29.tab.o 29.tab.h $(OBJ)
	gcc $(CFLAGS) -o 29 29.tab.o $(OBJ)
	
29.tab.c 29.tab.h: 29.y
	bison -d 29.y
	
lexer.o: 	lexer.c global.h
	gcc -Wall -c lexer.c

symbol.o: 	symbol.c global.h
	gcc -Wall -c symbol.c

error.o: 	error.c global.h
	gcc -Wall -c error.c

clean:
	$(RM) 29 29.tab.o 29.tab.c 29.tab.h lex.yy.o lex.yy.c
