#include "treenode.h"
#include "global.h"
#include "29.tab.hpp"

TreeNode* mkleaf(int type, int value){
	TreeNode* p = new TreeNode();
	p->type = type;
	p->leaf_value = value;
	return p;
}

TreeNode* mknode(int type, TreeNode* a0, TreeNode* a1, TreeNode* a2){
	TreeNode* p = new TreeNode();
	p->type = type;
	p->args[0] = a0;
	p->args[1] = a1;
	p->args[2] = a2;
	return p;
}

int execute(TreeNode* tree){

	if (tree->type == NUM)
		return tree->leaf_value;
		
	else if (tree->type == ID)
		return symtable[tree->leaf_value].value;
	else if (tree->type == '+')
	{
		int arg1 = execute(tree->args[0]);
		int arg2 = execute(tree->args[1]);
		
		return arg1+arg2;
	}
	
	else if (tree->type == '-')
	{
		int arg1 = execute(tree->args[0]);
		int arg2 = execute(tree->args[1]);
		
		return arg1-arg2;
	}
	
	else if (tree->type == '*')
	{
		int arg1 = execute(tree->args[0]);
		int arg2 = execute(tree->args[1]);
		
		return arg1*arg2;
	}
		
	else if (tree->type == '/')
	{
		int arg1 = execute(tree->args[0]);
		int arg2 = execute(tree->args[1]);
		
		return arg1/arg2;
	}		
	
	else if (tree->type == '^')
	{
		int arg1 = execute(tree->args[0]);
		int arg2 = execute(tree->args[1]);
		
		return power(arg1,arg2);
	}
	
	else if (tree->type == '%')
	{
		int arg1 = execute(tree->args[0]);
		int arg2 = execute(tree->args[1]);
		
		return arg1%arg2;
	}				

	else if (tree->type == '&')
	{
		int arg1 = execute(tree->args[0]);
		int arg2 = execute(tree->args[1]);
		
		return arg1&arg2;
	}		
	else if (tree->type == '|')
	{
		int arg1 = execute(tree->args[0]);
		int arg2 = execute(tree->args[1]);
		
		return arg1&arg2;
	}		
	else if (tree->type == '<')
	{
		int arg1 = execute(tree->args[0]);
		int arg2 = execute(tree->args[1]);
		
		return arg1<arg2;
	}		
	else if (tree->type == '>')
	{
		int arg1 = execute(tree->args[0]);
		int arg2 = execute(tree->args[1]);
		
		return arg1>arg2;
	}		
	
	else if (tree->type == '=')
	{
		int arg1 = execute(tree->args[0]);
		int arg2 = execute(tree->args[1]);
		
		return arg1 = arg2;
	}			

	else if (tree->type == AND)
	{
		int arg1 = execute(tree->args[0]);
		int arg2 = execute(tree->args[1]);
		
		return arg1 && arg2;
	}		
	
	else if (tree->type == OR)
	{
		int arg1 = execute(tree->args[0]);
		int arg2 = execute(tree->args[1]);
		
		return arg1 || arg2;
	}		
	
	else if (tree->type == NOT)
	{
		int arg1 = execute(tree->args[0]);
		return !arg1;
	}		
	
	else if (tree->type == IF)
		{
			int condition = execute(tree->args[0]);
			if (condition)
				return execute(tree->args[1]);
			else
				return execute(tree->args[2]);
		}
	
	else if (tree->type == WHILE)
	{
		int condition = execute(tree->args[0]);
		
		while(condition)
			return execute(tree->args[0]);
		
	}
	else if (tree->type == PRINT)
	{
		int arg1 = execute(tree->args[0]);
		
		return arg1;
	}			
	else if (tree->type == READ)
	{
		int arg1 = execute(tree->args[0]);
		
		scanf("%d", &arg1);
		
		return arg1;
	}		

}

void printtree1(TreeNode* p, int level) {
  if (p == 0)
    ;
  else if (p->type == ID) {
    printf("%*s", 2*level, "");
    printf("%s\n", symtable[p->leaf_value].lexptr);
  }
  else if (p->type == NUM) {
    printf("%*s", 2*level, "");
    printf("%d\n", p->leaf_value);
  }
  else if (p->type == IF) {
    printf("%*s", 2*level, "");
    printf("if\n");
    printtree1(p->args[0], level + 1);
    printtree1(p->args[1], level + 1);
  }
  else if (p->type == ELSE) {
    printf("%*s", 2*level, "");
    printf("else\n");
    printtree1(p->args[0], level + 1);

  }
  else if (p->type == WHILE) {
    printf("%*s", 2*level, "");
    printf("while\n");
    printtree1(p->args[0], level + 1);
    printtree1(p->args[1], level + 1);
  }
  else if (p->type == PRINT) {
    printf("%*s", 2*level, "");
    printf("print\n");
    printtree1(p->args[0], level + 1);
  }
  
  else if (p->type == READ) {
    printf("%*s", 2*level, "");
    printf("read\n");
    printtree1(p->args[0], level + 1);
    printtree1(p->args[1], level + 1);
  }
  else if (p->type == '+') {
    printf("%*s", 2*level, "");
    printf("+\n");
    printtree1(p->args[0], level + 1);
    printtree1(p->args[1], level + 1);
  }

  else if (p->type == '-') {
    printf("%*s", 2*level, "");
    printf("-\n");
    printtree1(p->args[0], level + 1);
    printtree1(p->args[1], level + 1);
  
  }  
  else if (p->type == '*') {
    printf("%*s", 2*level, "");
    printf("*\n");
    printtree1(p->args[0], level + 1);
    printtree1(p->args[1], level + 1);
  
  }
  else if (p->type == '/') {
    printf("%*s", 2*level, "");
    printf("/\n");
    printtree1(p->args[0], level + 1);
    printtree1(p->args[1], level + 1);
  
  }
  else if (p->type == '^') {
    printf("%*s", 2*level, "");
    printf("^\n");
    printtree1(p->args[0], level + 1);
    printtree1(p->args[1], level + 1);
  
  }
  else if (p->type == '%') {
    printf("%*s", 2*level, "");
    printf("%\n");
    printtree1(p->args[0], level + 1);
    printtree1(p->args[1], level + 1);
  
  }
  else if (p->type == '<') {
    printf("%*s", 2*level, "");
    printf("<\n");
    printtree1(p->args[0], level + 1);
    printtree1(p->args[1], level + 1);
  
  }
  else if (p->type == '>') {
    printf("%*s", 2*level, "");
    printf(">\n");
    printtree1(p->args[0], level + 1);
    printtree1(p->args[1], level + 1);
  
  }
  else if (p->type == '&') {
    printf("%*s", 2*level, "");
    printf("&\n");
    printtree1(p->args[0], level + 1);
    printtree1(p->args[1], level + 1);
  
  }
  else if (p->type == '|') {
    printf("%*s", 2*level, "");
    printf("|\n");
    printtree1(p->args[0], level + 1);
    printtree1(p->args[1], level + 1);
  
  }
  else if (p->type == '=') {
    printf("%*s", 2*level, "");
    printf("=\n");
    printtree1(p->args[0], level + 1);
    printtree1(p->args[1], level + 1);
  
  }       
  else if (p->type == ';') {
    printf("%*s", 2*level, "");
    printtree1(p->args[0], level + 1);
    printf("%*s", 2*level, "");
    printf(";\n");
    printtree1(p->args[1], level);
  }
}

void printtree(TreeNode* p) {
  printf("Syntax tree:\n");
  printtree1(p, 0);
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
