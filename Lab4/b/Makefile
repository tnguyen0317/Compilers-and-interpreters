CC = gcc
CFLAGS += -Wall -std=c99 -g
OBJ = lex.yy.o symbol.o 
SRC = symbol.c 


29: 29.tab.o 29.tab.h $(OBJ)
	gcc $(CFLAGS) -o 29 29.tab.o $(OBJ)
	
29.tab.c 29.tab.h: 29.y
	bison -d 29.y

lex.yy.c: 29.l
	flex 29.l

parser.o: 	parser.c global.h
	gcc -Wall -c parser.c

emitter.o: 	emitter.c global.h
	gcc -Wall -c emitter.c

symbol.o: 	symbol.c global.h
	gcc -Wall -c symbol.c

init.o: 	init.c global.h
	gcc -Wall -c init.c


clean:
	$(RM) 29 29.tab.o 29.tab.c 29.tab.h lex.yy.o lex.yy.c
