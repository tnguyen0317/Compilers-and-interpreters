#define MAX_ARGS 3

struct TreeNode {
	int type;
	int leaf_value;
	TreeNode* args[MAX_ARGS];
};

TreeNode* mkleaf(int type, int value){
	TreeNode* p = new TreeNode();
	p->type = type;
	p->leaf_value = value;
	return p;
}

TreeNode* mknode(int type, TreeNode* a0 = 0, TreeNode* a1 = 0, TreeNode* a2 = 0){
	TreeNode* p = new TreeNode();
	p->type = type;
	p->args[0] = a0;
	p->args[1] = a1;
	p->args[2] = a2;
	return p;
}

