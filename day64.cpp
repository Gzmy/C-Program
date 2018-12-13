#include <iostream>
#include <vector>

typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* reConstructBinaryTree(std::vector<int> pre, std::vector<int> vin) {
    if(vin.size() == 0){
        return NULL;
    }

    TreeNode *root = new TreeNode(pre[0]);

    std::vector<int> left_pre, left_in, right_pre, right_in;

    int tmp;
    for(int i = 0; i < vin.size(); i++){
        if(vin[i] == pre[0]){
            tmp = i;
            break;
        }
    }

    for(int i = 0; i < tmp; i++){
        left_pre.push_back(pre[i+1]);
        left_in.push_back(vin[i]);
    }

    for(int i = tmp+1; i < vin.size(); i++){
        right_in.push_back(vin[i]);
        right_pre.push_back(pre[i]);
    }

    root->left = reConstructBinaryTree(left_pre, left_in);
    root->right = reConstructBinaryTree(right_pre, right_in);

    return root;
}
