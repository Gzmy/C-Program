/*寻找相交链表的入口结点*/

#include <stdio.h>

typedef struct SListNode{
    int val;
    struct SListNode *next;
} SListNode;

SListNode *detectCycle(SListNode *head)
{
    SListNode *fast = head;
    SListNode *slow = head;

    while(fast && slow && fast->next){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
