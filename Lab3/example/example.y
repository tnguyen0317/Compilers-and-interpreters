/* example.y */

%{
#include <stdio.h>
extern int yyerror(char const *msg);
extern int yylex();
%}

%token PLUS MINUS STAR DIV LPAREN RPAREN NUMBER NEWLINE 
%left PLUS MINUS
%left STAR
%left DIV

%%
line : /* empty */
     | line expr NEWLINE      { printf("%d\n", $2); }
expr : LPAREN expr RPAREN     { $$ = $2; }
     | expr PLUS expr         { $$ = $1 + $3; }
     | expr MINUS expr        { $$ = $1 - $3; }
     | expr STAR expr         { $$ = $1 * $3; }
     | expr DIV expr					{ $$ = $1 / $3; }
     | NUMBER                 { $$ = $1; }

     ;

%%

int yyerror(char const *msg) {
    printf("Error: %s\n", msg);
    return 0;
}

int main() {
    printf("%d\n", yyparse());
    return 0;
}
