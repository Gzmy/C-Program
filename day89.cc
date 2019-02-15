#include <iostream>


typedef struct ListNode {
	int val;
	struct ListNode *next;
} ListNode;

//删除重复链表
ListNode* deleteDuplication(ListNode* pHead) {
	if(pHead == NULL || pHead->next == NULL) {
		return pHead;
	}

	ListNode *node = pHead;
	ListNode *cur = NULL;
	ListNode *old = NULL;

	while(node) {
		cur = node->next;
		int val = node->val;
		if(cur != NULL && cur->val == val) {
			while(cur != NULL && cur->val == val) {
				cur = cur->next;
			}

			if(old == NULL) {
				pHead = cur;
			} else {
				old->next = cur;
			}
			node = cur;
		} else {
			old = node;
			node = node->next;
		}
	}

	return pHead;
}

//二叉树的下一个结点

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *parent;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

typedef struct TreeLinkNode TreeLinkNode;

TreeLinkNode* GetNext(TreeLinkNode* pNode) {
	if(pNode == nullptr) {
		return nullptr;
	}

	TreeLinkNode *cur = nullptr;
	if(pNode->right != nullptr) {
		cur = pNode->right;
		while(cur->left) {
			cur = cur->left;
		}
	} else if (pNode->parent != nullptr) { 
		TreeLinkNode *par = pNode->parent;
		cur = pNode;
		while(par != nullptr && par->right == cur) {
			cur = par;
			par = par->parent;
		}
		cur = par;
	}

	return cur;
}
