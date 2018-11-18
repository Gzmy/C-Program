/*判断一个链表是否带环*/

#include <stdio.h>

typedef struct SListNode{
    int val;
    struct SListNode *next;
} SListNode;

bool hasCycle(SListNode *head)
{
    SListNode *fast = head;
    SListNode *slow = head;
    SListNode *cur = NULL;

    while(fast && slow){
        cur = fast->next;
        if(cur == NULL){
            break;
        }
        fast = cur->next;
        if(fast == NULL){
            break;
        }

        slow = slow->next;

        if(fast == slow){
            return true;
        }
    }

    return false;
}
