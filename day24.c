/*
 * 给定一个带有头结点head的非空单链表,返回链表中间结点
 * 如果有两个中间结点,则返回第二个中间结点
 */

#include <stdio.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode*middleNode(struct ListNode*head)
{
    if(head == NULL){
        return NULL;
    }
    struct ListNode *node = head;
    struct ListNode *next = head;

    while(next){
        if(next->next == NULL){
            break;
        }

        node = node->next;
        next = next->next->next;
    }

    return node;
}
