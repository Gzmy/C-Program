#include <iostream>
using namespace std;

//删除单向链表中间的某个结点，假定你只能访问该结点。
//给定待删除的节点，请执行删除操作，若该节点为尾节点，返回false，
//否则返回true

class Remove{
public:
    bool removeNode(ListNode *pNode)
    {
        if(pNode == NULL){
            return false;
        }

        ListNode *node = pNode->next;

        pNode->val = node->val;
        pNode->next = node->next;

        return true;
    }
};

//约瑟夫环I--牛客

int getResult(int n, int m)
{
    if(n <= 0 || m <= 0){
        return -1;
    }

    int sum = 0, i = 2;
    for(; i <= n; i++){
        s = (s+m) % i;
    }

    return s + 1;
}

//回文链表
bool isPalindrome(ListNode* head)
{
    if(head == NULL){
        return true;
    }


    static ListNode *node = NULL;
    if(node == NULL){
        node = head;
    }

    if(isPalindrome(head->next) && (node->val == head->val)){
        node = node->next;
        return true;
    }
    node = NULL;

    return false;
}
