#include <iostream>
#include <vector>
#include <queue>
#include <stack>

typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

//从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
std::vector<std::vector<int> > Print(TreeNode* pRoot) {
    std::vector<std::vector<int>> vec;
    if(pRoot == NULL){
        return vec;
    }

    std::queue<TreeNode*> q;
    std::vector<int> tmp;
    int thisVal = 1;
    int nextVal = 0;
    q.push(pRoot);

    while(!q.empty()){
        TreeNode *node = q.front();
        tmp.push_back(node->val);
        if(node->left){
            q.push(node->left);
            nextVal++;
        }
        if(node->right){
            q.push(node->right);
            nextVal++;
        }
        q.pop();
        thisVal--;
        if(thisVal == 0){
            vec.push_back(tmp);
            tmp.clear();
            thisVal = nextVal;
            nextVal = 0;
        }
    }

    return vec;
}

//按之字形顺序打印二叉树
std::vector<std::vector<int> > Print1(TreeNode* pRoot) {
    std::vector<std::vector<int>> vec;
    if(pRoot == NULL){
        return vec;
    }


    std::stack<TreeNode*> leves[2];
    std::vector<int> tmp;
    int cur = 0;
    int nex = 1;

    leves[cur].push(pRoot);
    while(!leves[cur].empty() || !leves[nex].empty()){
        TreeNode *node = leves[cur].top();
        leves[cur].pop();
        tmp.push_back(node->val);

        if(cur == 0){
            if(node->left){
                leves[nex].push(node->left);
            }
            if(node->right){
                leves[nex].push(node->right);
            }
        }else{
            if(node->right){
                leves[nex].push(node->right);
            }
            if(node->left){
                leves[nex].push(node->left);
            }
        }

        if(leves[cur].empty()){
            vec.push_back(tmp);
            tmp.clear();
            nex = 1 - nex;
            cur = 1 - cur;
        }
    }

    return vec;
}
