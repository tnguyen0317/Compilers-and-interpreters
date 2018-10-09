/* 29.l */

%{
#include <stdio.h>
#include "global.h"
#include "29.tab.h"

extern int yylval;

int fileno(FILE *stream);		//lagt till

%}

delim [ \t\n]
ws {delim}+
letter[A-Za-z]
digit [0-9]
id {letter}({letter}|{digit})*
num {digit}+

%option noyywrap

%%

[ \t\n]+    { /* ignore whitespace */ }
"("				{ return '('; }
")"				{ return ')'; }
"+"				{ return '+'; }
"-"				{ return '-'; }
"*"				{ return '*'; }
"/"				{ return '/'; }
"^"				{ return '^'; }
"="				{ return '='; }
"?"				{ return '?'; }
";"				{ return ';'; }
"<"				{ return '<'; }
">"				{ return '>'; }
":"				{ return ':'; }
"%"				{ return '%'; }
"&"				{ return '&'; }
"|"				{ return '|'; }
[0-9]+    { yylval = atoi(yytext); printf("[Found NUM %d]\n", yylval); return NUM; }
{id} 	  {
					int p;
					p = lookup(yytext);
					if (p == 0)
						p = insert(yytext,ID);
					
					yylval = p;
					return ID;
				}	
.         { printf("Ignoring invalid character '%s'\n", yytext); }
%% 
