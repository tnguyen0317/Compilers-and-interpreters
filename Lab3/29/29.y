%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include "29.tab.h"
	#include "global.h"
	
	extern int tokenval;
	
	extern void yyerror(char*);
	extern int yylex();
	extern int yyparse();
%}

%token DONE ID NUM

%left '+' '-'
%left '*' '/'
%left '^'


%%


start : start expr  { printf("%d\n", $2); }

expr : '(' expr ')'     { $$ = $2; }
     | expr '+' expr         { $$ = $1 + $3; }
     | expr '-' expr        { $$ = $1 - $3; }
     | expr '*' expr         { $$ = $1 * $3; }
     | expr '/' expr					{ $$ = $1 / $3; }
     | expr '^' expr				{ $$ = $1 ^ $3; }
     | NUM
     | ID 
     | /* empty */ 
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
	printf("%d\n", yyparse());
	return 0;
}

