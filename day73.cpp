#include <iostream>

typedef struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

class Solution{
	public:
		int getDepth(TreeNode *node){
			if(node == NULL){
				return 0;
			}

			int left = getDepth(node->left);
			int right = getDepth(node->right);

			return left > right ? left+1 : right+1;
		}

		bool IsBalanced_Solution(TreeNode* pRoot) {
			if(pRoot == NULL){
				return true;
			}

			int leftDepth = getDepth(pRoot->left);
			int rightDepth = getDepth(pRoot->right);

			if(leftDepth > rightDepth+1 || rightDepth > leftDepth+1){
				return false;
			}else{
				return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
			}
		}
};
