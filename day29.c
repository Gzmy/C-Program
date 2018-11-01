/*
 * 给定一个排序链表，删除所有重复的元素，
 * 使得每个元素只出现一次。
 */
#include <stdio.h>
struct ListNode{
	int val;
 	struct ListNode *next;
};
struct ListNode *deletDuplicates(struct ListNode *head)
{
	if(head == NULL || head->next == NULL){
		return NULL;
	}
	struct ListNode *node = head;

	while(node->next){
		if(node->val != node->next->val){
			node = node->next;
		}
		else{
			node->next = node->next->next;
		}
	}
	return head;
}
