#include <iostream>
using namespace std;

class Partition{
public:
    ListNode *partitionNode(ListNode *pHead, int x)
    {
        if(pHead == NULL){
            return NULL;
        }

        ListNode *small = new ListNode(0);
        ListNode *big = new ListNode(0);
        ListNode *smallHead = small;
        ListNode *bigHead = big;

        while(pHead){
            if(pHead->val < x){
                small->next = pHead;
                small = small->next;
            }else{
                big->next = pHead;
                big = big->next;
            }
            pHead = pHead->next;
        }

        small->next = bigHead->next;
        big->next = NULL;
        return smallHead;
    }
};
