#include <iostream>
#include <string>
#include <vector>

// 二叉树中和为某一值的路径

typedef struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

std::vector<std::vector<int> > res;
std::vector<int> tmp;

std::vector<std::vector<int> > findPath(TreeNode *root, int target) {
	if(root == NULL) {
		return res;
	}

	tmp.push_back(root->val);
	if((root->val)-target == 0 && root->left == NULL && root->right == NULL) {
		res.push_back(tmp);
	}

	findPath(root->left, target-root->val);
	findPath(root->right, target-root->val);

	if(!tmp.empty()) {
		tmp.pop_back();
	}

	return res;
}


// 将二叉搜索树转换成双向链表

void convertHelper(TreeNode *cur, TreeNode *&pre) {
	if(cur == NULL) {
		return;
	}

	convertHelper(cur->left, pre);

	cur->left = pre;
	if(pre) {
		pre->right = cur;
	}
	pre = cur;

	convertHelper(cur->right, pre);
}

TreeNode* convErt(TreeNode *pRootOfTree) {
	if(pRootOfTree == NULL) {
		return NULL;
	}

	TreeNode *pre = NULL;

	convertHelper(pRootOfTree, pre);

	TreeNode *res = pRootOfTree;
	while(res->left) {
		res = res->left;
	}

	return res;
}

