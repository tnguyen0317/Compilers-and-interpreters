OBJ = lexer.o parser.o emitter.o symbol.o init.o error.o main.o 
SRC = lexer.c parser.c emitter.c symbol.c init.c error.c main.c
EXE = infix2postfix

infix2postfix:	$(OBJ)
	gcc -Wall -o infix2postfix $(OBJ)

main.o: 	main.c global.h
	gcc -Wall -c main.c

lexer.o: 	lexer.c global.h
	gcc -Wall -c lexer.c

parser.o: 	parser.c global.h
	gcc -Wall -c parser.c

emitter.o: 	emitter.c global.h
	gcc -Wall -c emitter.c

symbol.o: 	symbol.c global.h
	gcc -Wall -c symbol.c

init.o: 	init.c global.h
	gcc -Wall -c init.c

error.o: 	error.c global.h
	gcc -Wall -c error.c

clean: 
	rm -f $(EXE) $(OBJ) 29.tar.gz 29.zip *~

archives: clean
	cd ..; rm 29.tar 29.zip 29/29.tar 29/29.zip; tar -cvf 29.tar 29; gzip -9 29.tar; zip -r 29.zip 29; mv 29.zip 29/29.zip; mv 29.tar.gz 29/29.tar.gz
