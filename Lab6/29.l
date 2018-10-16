/* 29.l */

%{
#include <stdio.h>
#include "global.h"
#include "treenode.h"
#include "29.tab.hpp"


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
"done"		{ return DONE;  }
"print"		{ return PRINT; }
"read"		{ return READ;	}
"if"			{ return IF;		}
"while"		{ return WHILE;	}
"else"		{ return ELSE;	}
"{"				{ return '{';		}
"}"				{ return '}';		}
[0-9]+    { yylval.i = atoi(yytext); return NUM; }
{id} 	  {
					int p;
					p = lookup(yytext);
					if (p == 0)
						p = insert(yytext,ID);
					
					yylval.i = p;
					return ID;
				}	
.         { printf("Ignoring invalid character '%s'\n", yytext); }
%% 
