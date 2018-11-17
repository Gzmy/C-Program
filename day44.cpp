/*
 * 在一个排序的链表中，存在重复的结点，
 * 请删除该链表中重复的结点，重复的结点不保留，
 * 返回链表头指针。 
 * 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
 */
#include <iostream>
#include <string>

typedef struct ListNode{
    int val;
    struct ListNode *next;
} ListNode;

class Solution{
public:
    ListNode *deleteDuplication(ListNode *pHead)
    {
        if(pHead == NULL || pHead->next == NULL){
            return pHead;
        }

        ListNode *node = pHead;
        ListNode *tmp = NULL;
        ListNode *cur = NULL;

        while(node){
            if(node->next != NULL && node->val == node->next->val){
                tmp = node->next;
                while(node != NULL && tmp != NULL && node->val == tmp->val){
                    tmp = tmp->next;
                }

                if(node == pHead){
                    pHead = tmp;
                }else{
                    cur->next = tmp;
                }
                node = tmp;
            }
            else{
                cur = node;
                node = node->next;
            }
        }

        return pHead;
    }
};
