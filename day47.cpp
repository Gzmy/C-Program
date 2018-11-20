/*
 * 删除链表重复元素
 * 1、1->2->3->3->4->4->5 --- 1->2->5
 * 2、
 */
#include <stdio.h>
typedef struct ListNode{
    int val;
    struct ListNode *next;
} ListNode;

ListNode *deleteDuplicates(ListNode *head)
{
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    struct ListNode *node = head;
    struct ListNode *cur = NULL;
    struct ListNode *Next = NULL;
    while(node){
        Next = node->next;
        int val = node->val;

        if(Next != NULL && val == Next->val){
            while(Next != NULL && Next->val == val){
                Next = Next->next;
            }
            if(cur == NULL){
                head = Next;
            }else{
                cur->next = Next;
            }
            node = Next;
        }
        else{
            cur = node;
            node = node->next;
        }
    }
    return head;
}
