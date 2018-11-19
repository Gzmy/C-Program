/*两两交换链表中的结点*/

#include <iostream>
using namespace std;

typedef struct ListNode{
    int val;
    struct ListNode *next;
} ListNode;

class Solution{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode *cur = head->next;
        head->next = swapPairs(cur->next);
        cur->next = head;

        return cur;
    }
};
