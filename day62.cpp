#include <iostream>
#include <vector>
#include <stack>

typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

//二叉树的前序遍历
std::vector<int> preorderTraversal(TreeNode* root){
    std::vector<int> vec;
    if(root == NULL){
        return vec;
    }

    std::stack<TreeNode*> s;
    TreeNode *node = root;
    while(node || !s.empty()){
        while(node){
            s.push(node);
            vec.push_back(node->val);
            node = node->left;
        }
        if(!s.empty()){
            node = s.top();
            s.pop();
            node = node->right;
        }
    }

    return vec;
} 

//中序
std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> vec;
    if(root == NULL){
        return vec;
    }

    std::stack<TreeNode*> s;
    while(root || !s.empty()){
        while(root){
            s.push(root);
            root = root->left;
        }
        if(!s.empty()){
            root = s.top();
            s.pop();
            vec.push_back(root->val);
            root = root->right;
        }
    }

    return vec;
}

//后序
std::vector<int> postorderTraversal(TreeNode* root) {
    std::vector<int> vec;
    if(root == NULL){
        return vec;
    }

    TreeNode* node = root;
    std::stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        node = s.top();
        if(node->left){
            s.push(node->left);
            node->left = NULL;
        }else if(node->right){
            s.push(node->right);
            node->right = NULL;
        }else{
            vec.push_back(node->val);
            s.pop();
        }
    }

    return vec;
}
