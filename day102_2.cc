#include <iostream>
#include <stack>
#include <limits.h>
#include <algorithm>

// leetcode 530 BST中任意两个节点差的最小值

typedef struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

int getMinimumDifference(TreeNode* root) {
	int res = INT_MAX, pre = -1;
	TreeNode* node = root;
	std::stack<TreeNode*> s;
	while(node || !s.empty()) {
		while(node) {
			s.push(node);
			node = node->left;
		}
		TreeNode* top = s.top();
		s.pop();
		if(pre != -1) {
			res = std::min(res, top->val - pre);
		}
		pre = top->val;
		node = top->right;
	}
	return res;
}
