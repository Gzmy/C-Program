//牛客剑指offer
#include <stdio.h>

int fib(int n)
{
    int Result[2] = {0, 1};
    if(n <= 2){
        return Result[n];
    }

    int fibOne = 0;
    int fibTwo = 1;
    int fibN = 0, i;
    for(i = 2; i <= n; i++){
        fibN = fibOne + fibTwo;

        fibOne = fibTwo;
        fibTwo = fibN;
    }

    return fibN;
}

//合并两个有序链表
ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
{
    if(pHead1 == NULL){
        return pHead2;
    }
    if(pHead2 == NULL){
        return pHead1;
    }

    ListNode *node = NULL;
    if(pHead1->val < pHead2->val){
        node = pHead1;
        node->next = Merge(pHead1->next, pHead2);
    }else{
        node = pHead2;
        node->next = Merge(pHead1, pHead2->next);
    }

    return node;
}

//二叉树的镜像
void Mirror(TreeNode *pRoot)
{
    if(pRoot == NULL){
        return;
    }
    if(pRoot->left == NULL && pRoot->right == NULL){
        returnl
    }

    TreeNode *node = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = node;

    if(pRoot->left){
        Mirror(pRoot->left);
    }
    if(pRoot->right){
        Mirror(pRoot->right);
    }
}

int main()
{
    int n = fib(3);
    printf("%d\n", n);
}
