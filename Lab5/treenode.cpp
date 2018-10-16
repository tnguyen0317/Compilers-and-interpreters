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
