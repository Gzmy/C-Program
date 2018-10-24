/*
 *删除链表中等于给定值 val 的所有节点。
 *示例:
 *输入: 1->2->6->3->4->5->6, val = 6
 *输出: 1->2->3->4->5
 */

#include <stdio.h>

/*
 *   Definition for singly-linked list.
 *   struct ListNode {
 *		 int val;
 *		struct ListNode *next;
 *   };
 *
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    
    if(head == NULL){
        return NULL;
    }
    
    struct ListNode *pre = head;
    struct ListNode *cur = head->next;
    
    while(cur){
        if(cur->val == val){
            pre->next = cur->next;
            free(cur);
            cur = pre->next;
        }
        else{
            pre = cur;
            cur = cur->next;
        }
    }
    
    struct ListNode *del;
    if(head->val == val){
        del = head;
        head = head->next;
        free(del);
    }
    
    return head;
}
