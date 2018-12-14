#include <iostream>
#include <vector>


typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

//二叉树中和为某一值的路径

std::vector<std::vector<int>> vec;
std::vector<int> tmp;

std::vector<std::vector<int>> FindPath(TreeNode* root,int expectNumber) {
    if(root == NULL){
        return vec;
    }

    tmp.push_back(root->val);
    if((root->val)-expectNumber == 0 && root->left == NULL && root->right == NULL){
        vec.push_back(tmp);
    }

    FindPath(root->left, expectNumber-root->val);
    FindPath(root->right, expectNumber-root->val);

    if(tmp.size() != 0){
        tmp.pop_back();
    }

    return vec;
}

