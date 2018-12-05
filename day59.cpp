#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

class includeMinStack{
public:
    void push(int val){
        if(stackNor.empty()){
            stackNor.push(val);
            stackMin.push(val);
            return;
        }

        if(val < stackNor.top()){
            stackNor.push(val);
            stackMin.push(val);
        }
        else{
            stackNor.push(val);
        }
    }

    void pop(){
        if(stackNor.empty()){
            return;
        }

        if(stackNor.top() == stackMin.top()){
            stackNor.pop();
            stackMin.pop();
        }else{
            stackNor.pop();
        }
    }

    int top(){
        return stackNor.top();
    }

    int min(){
        return stackMin.top();
    }
private:
    std::stack<int> stackNor; 
    std::stack<int> stackMin;
};

//从上往下打印出二叉树的每个节点，同层节点从左至右打印。
typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

class Solution{
public:
    vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        vector<int> vec;
        queue<TreeNode *> queueNode;

        if(root == NULL){
            return vec;
        }

        queueNode.push(root);
        while(queueNode.size()){
            TreeNode *node = queueNode.front();
            queueNode.pop();

            vec.push_back(node->val);

            if(node->left){
                queueNode.push(node->left);
            }
            if(node->right){
                queueNode.push(node->right);
            }
        }

        return vec;
    }
};
