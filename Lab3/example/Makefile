CC = gcc
CFLAGS += -Wall -std=c99 -g

example: example.tab.o example.tab.h lex.yy.o
	gcc $(CFLAGS) -o example example.tab.o lex.yy.o

example.tab.c example.tab.h: example.y
	bison -d example.y

lex.yy.c: example.l
	flex example.l

clean:
	$(RM) example example.tab.o example.tab.c example.tab.h lex.yy.o lex.yy.c
