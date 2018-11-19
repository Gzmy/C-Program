/*相交链表找交点*/

#include <stdio.h>

typedef struct SListNode{
    int val;
    struct SListNode *next;
} SListNode;

static int getlen(SListNode *head)
{
    int len = 0;
    while(head){
        head = head->next;
        len++;
    }
    return len;
}

SListNode *getIntersectionNode(SListNode *headA, SListNode *headB)
{
    if(!headA || !headB){
        return NULL;
    }

    int lenA = getlen(headA);
    int lenB = getlen(headB);

    if(lenA > lenB){
        int i = 0;
        for(; i < lenA-lenB; i++){
            headB = headB->next;
        }
    }
    else{
        int i = 0;
        for(; i < lenB-lenA; i++){
            headA = headA->next;
        }
    }

    while(headA && headB){
        if(headA == headB){
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}
