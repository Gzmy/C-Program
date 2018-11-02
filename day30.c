/*
 * 找到两个链表的相交起始结点
 */
#include <stdio.h>
struct ListNode{
    int val;
    struct ListNode *next;
};

int getlen(struct ListNode *node)
{
    int len = 0;
    while(node){
        node = node->next;
        len++;
    }
    return len;
}

struct ListNode *getInsertionode(struct ListNode *headA, struct ListNode *headB)
{
    if(!headA || !headB){
        return NULL;
    }
    int lena = getlen(headA);
    int lenb = getlen(headB);

    if(lena < lenb){
        int i = 0;
        for(; i < lenb-lena; i++){
            headB = headB->next;
        }
    }
    else{
        int i = 0;
        for(; i < lena-lenb; i++){
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
