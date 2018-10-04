list: assignment ';' list
				| expr ';' list
				| /* empty */
				;
				
				
assignment:	ID '=' expr
					;
expr: expr '+' term { printf('+'); }
					|	'-' term { printf('-'); }
					| NUM
					| ID
					| /* empty */
					;

term: term '*' factor { printf('*'); }
					| '/' factor { printf('/'); }
					| /*empty*/
					| NUM
					| ID
					;
					
factor: factor '^' exponent { printf('^'); } 
					| NUM
					| ID
					| /* empty */
					;

exponent: '(' expr ')' 
					| ID { printf("%s\n", symtable[tokenval].lexptr); } 
					| NUM { printf("%d\n", tokenval); }
					| /* empty */
					;

