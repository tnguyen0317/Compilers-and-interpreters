/* 29.l */

%{
#include <stdio.h>

%}


%option noyywrap

%%

[ \t]+    { /* ignore whitespace */ }

[0-9]+    { yylval = atoi(yytext); return NUM; }
.         { printf("Ignoring invalid character '%s'\n", yytext); }


%% 
