#include <iostream>

typedef struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

class Solution{
	public:
		char *Serialize(TreeNode *root){
			if(!root){
				return '$';
			}
			std::string ret = to_string(root->val);
			ret.push_back(',');
			char *left = Serialize(root->left);
			char *right = Serialize(root->right);
			char *res = new char[strlen(left) + strlen(right) + ret.size()];
			strcpy(res, r.c_str());
			strcat(res, left);
			strcat(res, right);
			return res;
		}

		TreeNode *Deserialize(char *str){
			if(*str == '$'){
				str++;
				return NULL;
			}
			int num = 0;
			while(*str != ','){
				num = num*10 + (*(str++)-'0');
			}
			str++;
			TreeNode *root = new TreeNode(num);
			root->left = Deserialize(str);
			root->right = Deserialize(str);
			return root;
		}
};
