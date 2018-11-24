/*剑指offer，找到链表环的入口结点*/

#include <iostream>
using namespace std;

typedef struct ListNode{
    int val;
    struct ListNode *next;
} ListNode;

class Solution{
public:
    ListNode *EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == NULL){
            return NULL;
        }

        ListNode *fast = pHead;
        ListNode *slow = pHead;

        while(fast->next){
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow){
                int count = 1;
                ListNode *node = fast->next;
                while(node != fast){
                    count++;
                    node = node->next;
                }
                fast = pHead;
                slow = pHead;
                while(count--){
                    fast = fast->next;
                }

                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return NULL;
    }
};

//剑指offer两个链表的公共结点

int GetLen(ListNode *node){
    int len = 0;
    if(node == NULL){
        return len;
    }

    while(node){
        len+;
        node = node->nextl
    }

    return len;
}

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2 ){
    if(pHead1 == NULL || pHead2 == NULL){
        return NULL;
    }

    int len1 = GetLen(pHead1);
    int len2 = GetLen(pHead2);
    
    int size = len1 - len2;
    ListNode *longList = pHead1;
    ListNode *shortList = pHead2;

    if(len1 < len2){
        size = len2 - len1;
        longList = pHead2;
        shortList = pHead1;
    }

    while(size--){
        longList = longList->next;
    }

    while(longList != shortList){
        longList = longList->next;
        shortList = shortList->next;
    }

    return shortList;
}
