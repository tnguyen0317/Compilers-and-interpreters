#include "treenode.h"

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


