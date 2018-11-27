//二叉树搜索树与双向链表

#include <iostream>
using namespace std;

typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

class Solution{
public:
    void ConvertNode(TreeNode *pNode, TreeNode **LastNode)
    {
        if(pNode == nullptr){
            return;
        }
        TreeNode *cur = pNode;
        if(cur->left != nullptr){
            ConvertNode(cur->left, LastNode);
        }
        cur->left = *LastNode;
        if(*LastNode != nullptr){
            (*LastNode)->right = cur;
        }

        *LastNode = cur;
        if(cur->right != nullptr){
            ConvertNode(cur->right, LastNode);
        }
    }

    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        TreeNode *LastNode = nullptr;
        ConvertNode(pRootOfTree, &LastNode);

        TreeNode *pHead = LastNode;
        while(pHead != nullptr && pHead->left != nullptr){
            pHead = pHead->left;
        }

        return pHead;
    }
};
