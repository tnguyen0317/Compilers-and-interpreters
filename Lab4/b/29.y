%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include "29.tab.h"
	#include "global.h"
	extern int yytext;
	extern int tokenval;
	extern void yyerror(char*);
	extern int yylex();
	extern int yyparse();
	int power();
%}

%token DONE ID NUM

%right '='
%right ':'
%right '?'
%left '|'
%left '&'
%nonassoc '<' '>'
%left '+' '-'
%left '*' '/' '%'
%left '^'

%%

start : start expr ';' { printf("%d\n", $2); }
	| start assignment ';'
	| /* empty */ 
	;

expr : '(' expr ')'     { $$ = $2; }
     | expr '+' expr    { $$ = $1 + $3; printf("[Added %d and %d]\n", $1, $3); }
     | expr '-' expr    { $$ = $1 - $3; }
     | expr '*' expr    { $$ = $1 * $3; }
     | expr '/' expr	{ $$ = $1 / $3; }
     | expr '^' expr	{ $$ = power($1, $3); }
     | expr '%' expr	{ $$ = $1 % $3; }
     | expr '&' expr	{ $$ = $1 & $3; }
     | expr '|' expr	{ $$ = $1 | $3; }
     | expr '<' expr	{ $$ = ($1 < $3); }
     | expr '>' expr	{ $$ = ($1 > $3); }
     | expr '?' expr ':' expr	{ $$ = ($1 ? $3 : $5); }
     | NUM            {  printf("[NUM %d]\n", $1); $$ = $1;  }
     | ID							{	$$ = symtable[$1].value; }
     ;

assignment : ID '=' expr	{ symtable[$1].value = $3; printf("[%s=%d]\n",symtable[$1].lexptr, $3); }
			;



%%


int power(int base, int exp)
{
	if (exp == 0)
		return 1;
		
	int i,  result =1;
	for(i=0; i<exp; i++)
		{
			result *= base;
		}
	return result;
		
}

void yyerror(char *s) {
		fprintf(stderr, "%s\n", s);
}			

//TAGIT BORT YYLEX(VOID)

void parse() {
	yyparse();
}

int main() {
	printf("%d\n", yyparse());
	return 0;
}

