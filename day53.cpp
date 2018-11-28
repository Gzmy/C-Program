#include <iostream>
using namespace std;

//第一个值只出现一次的字符
int FirstNotRepeatingChar(string s)
{
    int i = 0;
    int table[256] = {0};

    while(s[i]){
        table[s[i]]++;
        i++;
    }

    i = 0;
    while(s[i]){
        if(table[s[i]] == 1){
            return i;
        }
    }

    return -1;
}

//二叉树的深度
int TreeDepth(TreeNode* pRoot)
{
    if(pRoot == NULL){
        return 0;
    }

    if(pRoot->left == NULL && pRoot->right == NULL){
        return 1;
    }

    int left = TreeDepth(pRoot->left) + 1;
    int right = TreeDepth(pRoot->right) + 1;

    return left > right ? left : right;
}

//二插搜索树的第K大结点
TreeNode *KthNodeCore(TreeNode *pRoot, int &k)
{
    TreeNode *node = NULL;
    if(pRoot->left != NULL){
        node = KthNodeCore(pRoot->left, k);
    }

    if(node == NULL){
        if(k == 1){
            node = pRoot;
        }
        k--;
    }

    if(node == NULL && pRoot->right != NULL){
        node = KthNodeCore(pRoot->right, k);
    }

    return node;
}

TreeNode* KthNode(TreeNode* pRoot, int k)
{
    if(pRoot == NULL || k <= 0){
        return NULL;
    }

    return KthNodeCore(pRoot, k);
}

//二叉树的下一个结点
TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
    if(pNode == NULL){
        return NULL;
    }

    TreeLinkNode *pNext = NULL;
    if(pNode->right != NULL){
        TreeLinkNode *node = pNode->right;
        while(node->left){
            node = node->left;
        }
        pNext = node;
    }
    else if(pNode->next != NULL){
        TreeLinkNode *cur = pNode;
        TreeLinkNode *parent = pNode->next;
        while(parent != NULL && cur == parent->right){
            cur = parent;
            parent = parent->next;
        }
        pNext = parent;
    }

    return pNext;
}
