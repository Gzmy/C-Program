/*
 *  合并两个有序链表,合并后依然有序.
 */
#include <stdio.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

ListNode *mergTwoLists(ListNode *l1, ListNode *l2)
{
    if(l1 == NULL){
        return l2;
    }else if(l2 == NULL){
        return l1;
    }else if(l1 == NULL && l2 == NULL){
        return NULL;
    }

    ListNode *node1 = l1;
    ListNode *node2 = l2;
    ListNode *Result = NULL;
    ListNode *cur = NULL;

    if(node1->val <= node2->val){
        Result = node1;
        node1 = node1->next;
        cur = Result;
    }
    else{
        Result = node2;
        node2 = node2->next;
        cur = Result;
    }

    while(node1 && node2){
        if(node1->val <= node2->val){
            cur->next = node1;
            node1 = node1->next;
        }
        else{
            cur->next = node2;
            node2 = node2->next;
        }
        cur = cur->next;
    }

    if(node1 == NULL){
        cur->next = node2;
    }
    else{
        cur->next = node1;
    }

    return Result;
}
