/* 29.l */

%{
#include <stdio.h>
#include "global.h"
#include "29.tab.h"

extern int yylval;

int fileno(FILE *stream);		//lagt till

%}

delim [\t\n]
ws {delim}+
letter[A-Z a-z]
digit [0-9]
id {letter}({letter}|{digit})*
num {digit}+

%option noyywrap
%option noinput
%option nounput

%%
{ws}
{id} 	  {yylval = symtable[yylval].value;}
[ \t]+    { /* ignore whitespace */ }

[0-9]+    { yylval = atoi(yytext); return NUM; }
.         { printf("Ignoring invalid character '%s'\n", yytext); }


%% 
