/* emitter.c */

#include "global.h"

#define MAX 10
int top = -1;

int stack[MAX];

void push(int num)
{
   if (top==MAX-1)
   {
	printf("\nStack is full!!");
   }
   else
   {
   	++top;
        stack[top]=num;
   }
}

int pop()
{
  if (top < 0)
    return 0;
  else
  {
    int nummer = stack[top--];
    return nummer;
  }

}

int size()
{
   int numberofelements = sizeof(stack)/sizeof(stack[0]);
   return numberofelements;
}

int power(int base, int exp)
{
  if (exp == 0)
    return 1;


  int i, result = 1;
  for (i = 0; i < exp; i++)	
    result *= base;
  return result;

}

void calculate(char operator)
{
	int var1,var2;
	var1 = pop();
	var2 = pop();
	if (operator == '+')
	  push(var1+var2);

	else if (operator == '-')
	  push(var1-var2);

	else if (operator == '*')
	  push(var1*var2);

	else if (operator == '/')
	  push(var1/var2);

	else if (operator == '^')
	  push(power(var2,var1));
}

void emit (int t, int tval)  /*  generates output  */
{
  switch(t) {
    case '+' :
	printf("%c\n", t);
	calculate(t);

	break;
    case '-' :
	printf("%c\n", t);
	calculate(t);

  	break;
    case '^':
	printf("%c\n", t);
	calculate(t);

	break;
    case '*' :
	printf("%c\n", t);
	calculate(t);

  	break;
    case '/' :
	printf("%c\n", t);
	calculate(t);

  	break;
    case '=' :

	symtable[tval].value = pop();

    	pop();

	printf("%c\n", t);
	printf("Assigned value of %s = %d\n",symtable[tval].lexptr,symtable[tval].value);
	break;
    case DIV:
    	printf("DIV\n"); break;
    case MOD:
    	printf("MOD\n"); break;
    case NUM:
    	printf("%d\n", tval);
	push(tval);
	break;
    case ID:
  	if (top == -1) // om vi är i början av stacken vet vi att det är variabeln av ID:t.
   	push(symtable[tval].token);
  	else // är vi inte i början av stacken är vi kommer vi troligtvis befinna oss efter = 												tecknet,
    		//vilket innebär att det är själva värdet av variabeln av ID:t
   	push(symtable[tval].value);

   	printf("%s\n", symtable[tval].lexptr);
	break;
  	default:    
    	printf("token %d, tokenval %d\n", t, tval);
	break;
  	}
}
