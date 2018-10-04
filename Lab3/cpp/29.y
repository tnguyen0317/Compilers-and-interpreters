%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include "29.tab.h"
	#include "global.h"
	#include "math.h"

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


line : /* empty */
			| line assignment ';' //{ printf("%d\n", $2); }
			| line expr ';' { printf("%d\n", $2); }

	  
assignment :
			|	ID '=' expr { $1 = symtable[tokenval].value = $3 ; printf("symval%d\ntval=%d\n", symtable[tokenval].value,tokenval); }  //symtable[tokenval].value = $3 ; printf("%d\n", symtable[yylval].value);
			

expr : '(' expr ')'     { $$ = $2; }
     | expr '+' expr    { $$ = $1 + $3; }
     | expr '-' expr    { $$ = $1 - $3; }
     | expr '*' expr    { $$ = $1 * $3; }
     | expr '/' expr		{ $$ = $1 / $3; }
     | expr '^' expr		{ $$ = power($1,$3); }
     | expr '%' expr		{	$$ = $1 % $3;	}
     | expr '&' expr		{ $$ = $1 & $3;	}
     | expr '|' expr		{ $$ = $1 | $3;	}
     | expr '<' expr		{ $$ = $1 < $3;	}
     | expr '>' expr		{ $$ = $1 > $3;	}
     | expr '&' expr		{ $$ = $1 & $3;	}
     | expr '?' expr ':' expr		{ $$ = ($1 ? $3 : $5);	}
     | NUM							{ $$ = $1 ; }
     | ID								{ $$ = symtable[tokenval].value; printf("ID tval%d\n", tokenval);}

     
     ;



%%

int power(int base, int exp)
{
  		if (exp == 0)
    		return 1;


  		int i, result = 1;
  		for (i = 0; i < exp; i++)	
    		result *= base;
  		return result;

}

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

