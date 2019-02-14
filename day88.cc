#include <iostream>
#include <vector>
#include <algorithm>

struct randomListNode {
	int val;
	struct randomListNode *next, *random;
	randomListNode(int x) : val(x), next(NULL), random(NULL) {}
};

typedef struct randomListNode randomListNode;

randomListNode* Clone(randomListNode* pHead) {
	if(pHead == nullptr) {
		return nullptr;
	}

	randomListNode *node = pHead;

	while(node) {
		randomListNode *cur = new randomListNode(node->val);
		cur->next = node->next;
		node->next = cur;
		node = cur->next;
	}

	node = pHead;
	while(node) {
		if(node->random != nullptr) {
			node->next->random = node->random->next;
		}
		node = node->next->next;
	}

	node = pHead;
	randomListNode *cur = node->next;
	randomListNode *tmp = node->next;

	node->next = tmp->next;
	node = node->next;

	while(node) {
		tmp->next = node->next;
		tmp = tmp->next;
		node->next = tmp->next;
		node = node->next;
	}

	return cur;
}

//字符串的排列

void premutation(std::string, size_t);

std::vector<std::string> result;
std::vector<std::string> preMutation(std::string str) {
	if(str.empty()) {
		return result;
	}

	premutation(str, 0);
	std::sort(result.begin(), result.end());
	return result;
}

void premutation(std::string s, size_t num) {
	if(s.size() == num) {
		result.push_back(s);
		return;
	}

	for(size_t i = num; s[i] != '\0'; i++) {
		if(i != num && s[num] == s[i]) {
			continue;
		}

		std::swap(s[num], s[i]);
		premutation(s, num+1);
		std::swap(s[num], s[i]);
	}
}
