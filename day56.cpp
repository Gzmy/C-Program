/*
 * struct ListNode{
 *      int val;
 *      struct ListNode *next;
 *      ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

class Plus{
public:
    ListNode *plusAB(ListNode *A, ListNode *B)
    {
        if(a == NULL && b == NULL){
            return NULL;
        }
        int flag = 0, sum = 0, val_sum = 0;
        ListNode *pHead = new ListNode(0);
        ListNode *node = pHead;

        while(a || b || flag){
            int val_a = (a != NULL ? a->val : 0);
            int val_b = (b != NULL ? b->val : 0);
            sum = val_a + val_b + flag;
            val_sum = sum % 10;
            flag = sum / 10;

            ListNode *newNode = new ListNode(val_sum);
            node->next = newNode;
            node = node->next;
            a = (a == NULL ? NULL : a->next);
            b = (b == NULL ? NULL : b->next);
        }
        return pHead->next;
    }
};
