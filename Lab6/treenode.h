#ifndef _TREENODE_H_
#define _TREENODE_H_

#define MAX_ARGS 3

#include <stdio.h>

struct TreeNode {
	int type;
	int leaf_value;
	TreeNode* args[MAX_ARGS];

};
	
extern TreeNode* mkleaf(int type, int value);

extern TreeNode* mknode(int type, TreeNode* a0 = 0, TreeNode* a1 = 0, TreeNode* a2 = 0);

void printtree1(TreeNode* p, int level);

void printtree(TreeNode* p);

int execute(TreeNode* tree);

int power(int base, int exp);


#endif
