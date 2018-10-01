/* example.lex */

%{
#include <stdio.h>
#include "example.tab.h"
%}

%option noyywrap

%%

[ \t]+    { /* ignore whitespace */ }
"("       { return LPAREN; }
")"       { return RPAREN; }
"+"       { return PLUS; }
"-"       { return MINUS; }
"*"       { return STAR; }
"/"				{ return DIV;	}
\n        { return NEWLINE; }
[0-9]+    { yylval = atoi(yytext); return NUMBER; }
.         { printf("Ignoring invalid character '%s'\n", yytext); }

%%
