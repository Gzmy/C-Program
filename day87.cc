#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

typedef struct ListNode {
	int val;
	struct ListNode *next;
} ListNode;

typedef struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

//offer fibonacci
int Fibonacci(int n) {
	int arr[3] = {0, 1, 1};
	if(n <= 2) {
		return arr[n];
	}

	int f3 = 1, f2 = 1;
	int f1 = 0;
	while(n > 2) {
		n -= 1;
		f1 = f2;
		f2 = f3;
		f3 = f1 + f2;
	}

	return f3;
}

//调整数组顺序使奇数位于偶数前面
void reOrderArray(std::vector<int> &array) {
	if(array.empty()) {
		return;
	}

	for(size_t i = 0; i < array.size(); i++) {
		for(size_t j = array.size()-1; j > i; j--) {
			if(array[j]%2 == 1 && array[j-1]%2 == 0) {
				std::swap(array[j], array[j-1]);
			}
		}
	}
}


//输入一个链表，输出该链表中倒数第k个结点。
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if(pListHead == nullptr || k <= 0) {
		return nullptr;
	}
	ListNode *fast = pListHead;
	ListNode *slow = pListHead;
	for(unsigned int i = 0; i < k-1; i++) {
		fast = fast->next;
		if(!fast) {
			return nullptr;
		}
	}

	while(fast->next) {
		fast = fast->next;
		slow = slow->next;
	}

	return slow;
}

//操作给定的二叉树，将其变换为源二叉树的镜像。
void Mirror(TreeNode *pRoot) {
	if(pRoot->left == nullptr && pRoot->right == nullptr) {
		return;
	}

	TreeNode *node = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = node;

	if(!pRoot->left) {
		Mirror(pRoot->left);
	}

	if(!pRoot->right) {
		Mirror(pRoot->right);
	}
}

//包含min函数的栈
std::stack<int> stackMin;
std::stack<int> stackNor;

void push(int val) {
	if(stackMin.empty()) {
		stackMin.push(val);
		stackNor.push(val);
	}

	if(val < stackMin.top()) {
		stackMin.push(val);
		stackNor.push(val);
	} else {
		stackNor.push(val);
	}
}

void pop() {
	if(stackMin.top() == stackNor.top()) {
		stackNor.pop();
		stackMin.pop();
	} else {
		stackNor.pop();
	}
}

int top() {
	return stackNor.top();
}

int min() {
	return stackMin.top();
}

//栈的压入、弹出序列
bool IsPopOrder(std::vector<int> pushV, std::vector<int> popV) {
	if(pushV.empty() || popV.empty()) {
		return false;
	}
	std::stack<int> stackData;
	int id = 0;

	for(size_t i = 0; i < popV.size(); i++) {
		while(stackData.empty() || stackData.top() != popV[i]) {
			stackData.push(pushV[id++]);
		}
		if(stackData.top() == popV[i]) {
			stackData.pop();
		}
	}

	if(!stackData.empty()) {
		return false;	
	} else {
		return true;
	}
}

//从上往下打印出二叉树的每个节点，同层节点从左至右打印。
std::vector<int> PrintFromTopToBottom(TreeNode* root){
	std::vector<int> res;
	if(root == nullptr) {
		return res;
	}

	std::queue<TreeNode *> queueNode;

	queueNode.push(root);
	while(queueNode.size()) {
		TreeNode *node = queueNode.front();

		res.push_back(node->val);

		if(node->left) {
			queueNode.push(node->left);
		}
		if(node->right) {
			queueNode.push(node->right);
		}
	}

	return res;
}

//二叉搜索树的后序遍历序列
bool VerifySquenceOfBST(std::vector<int> sequence) {
	if(sequence.empty()) {
		return false;
	}

	int size = sequence.size();
	int i = 0;

	while(--size) {
		while(sequence[i++] < sequence[size]);
		while(sequence[i++] > sequence[size]);

		if(i < size) {
			return false;
		}
		i = 0;
	}

	return true;
}

//二叉树中和为某一值的路径
std::vector<int> tmp;
std::vector<std::vector<int>> res;

std::vector<std::vector<int> > FindPath(TreeNode* root,int expectNumber) {
	if(root == nullptr) {
		return res;
	}

	tmp.push_back(root->val);
	if((root->val)-expectNumber == 0 && root->left == nullptr && root->right == nullptr) {
		res.push_back(tmp);
	}

	FindPath(root->left, expectNumber-(root->val));
	FindPath(root->right, expectNumber-(root->val));

	if(!tmp.empty()) { //!!!无论是否满足都要出队列
		tmp.pop_back();
	}

	return res;
}
