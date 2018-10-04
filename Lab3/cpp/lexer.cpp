/* lexer.c */

#include "29.tab.hpp"
#include "global.h"

#define BSIZE  128  /* buffer size */
#define NONE   -1
#define EOS    '\0'

char lexbuf[BSIZE];
int  lineno = 1;
int  tokenval = NONE;


int lexan ()  /*  lexical analyzer  */
{

  int t;
  while(1) {
    t = getchar ();
    if (t == ' ' || t == '\t')
      ;  /*  strip out white space  */
    else if (t == '\n')
      lineno = lineno + 1;
    else if (isdigit (t)) {  /*  t is a digit  */
      ungetc(t, stdin);
      scanf("%d", &yylval);
      return NUM;
    }
    else if (isalpha(t)) {  /*  t is a letter */
    	//yylval = p;
      int p, b = 0;
      while (isalnum(t)) {  /* t is alphanumeric  */
        lexbuf [b] = t; 
        t = getchar ();

        b = b + 1;
        if (b >= BSIZE)
          error((char *)"compiler error");
      }
      lexbuf[b] = EOS;
      if (t != EOF)
        ungetc(t, stdin);
      p = lookup (lexbuf);
      if (p == 0){
        p = insert (lexbuf, ID);
        printf("id inserted in symtable::p=%d\n",p);
        printf("lexbuf=%s\n", lexbuf);
        }
      tokenval = p;
      //printf("yytext=%s\n",yytext);
      printf("p=%d\n",p);
      //yylval = p;
      return symtable[p].token;
    }
    else if (t == EOF)
      return DONE;
    else {
      tokenval = NONE;
      return t;
    }
  }
}
