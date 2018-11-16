/*
 * 对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。
 *
 * 给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
 * 
 */

typedef struct ListNode{
    int val;
    struct ListNode *next;
} ListNode;

#include <stdio.h>

bool chkPalindrome(ListNode *A)
{
    if(A == NULL){
        return false;
    }
    if(A->next == NULL){
        return true;
    }

    int arr[1000] = {0};
    ListNode *node = A;
    int i = 0, j, k = 0;
    while(node){
        arr[i++] = node->val;
        node = node->next;
    }
    for(j = i-1; j >= i/2; j--){
        if(arr[k++] == arr[j]){
            continue;
        }
        return false;
    }
    return true;
}
