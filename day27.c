/*
 * 删除链表倒数第k个结点
 */

#include <stdio.h>
#include <stdlib.h>
struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *node = head;
    struct ListNode *cur = head;
    struct ListNode *del = NULL;
    int sum = 0;
    if(head->next == NULL && n == 1){
        return NULL;
    }
    while(node){
        node = node->next;
        sum++;
    }
    if(n == sum){
        cur = head;
        head = head->next;
        free(cur);
        return head;
    }
    node = head;
    cur = head;
    while(--n){
        cur = cur->next;
    }
    while(cur->next){
        del = node;
        node = node->next;
        cur = cur->next;
    }
    del->next = node->next;
    free(node);
    return head;
}
