%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include "29.tab.h"
	#include "lexer.c"
	
	extern int tokenval;
	
	extern void yyerror(char*);
	extern int yylex(void);
	extern int yyparse();
%}

%token DONE ID NUM DIV MOD PLUS MINUS STAR DIV EXP LPAREN RPAREN NUMBER NEWLINE
%left PLUS MINUS
%left STAR DIV
%left EXP


%%

start: DONE
				;

%%



void yyerror(char *s) {
		fprintf(stderr, "%s\n", s);
}			

int yylex(void) {
	return lexan();
}

void parse() {
	yyparse();
}

int main() {
	yyparse();
	return 0;
}

