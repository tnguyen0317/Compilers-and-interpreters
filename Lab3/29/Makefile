CC = gcc
CFLAGS += -Wall -std=c99 -g

29: 29.tab.o 29.tab.h lex.yy.o
	gcc $(CFLAGS) -o 29 29.tab.o lex.yy.o
	
29.tab.c 29.tab.h: 29.y
	bison -d 29.y
	
lex.yy.c: 29.l
	flex 29.l
	
clean:
	$(RM) 29 29.tab.o 29.tab.c 29.tab.h lex.yy.o lex.yy.c
