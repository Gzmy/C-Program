/*输入一个链表，输出该链表中倒数第k个结点。*/

#include <iostream>
using namespace std;

typedef struct ListNode{
    int val;
    struct ListNode *next;
} ListNode;

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
    if(pListHead == nullptr || k == 0){
        return nullptr;
    }

    ListNode *fast = pListHead;
    ListNode *slow = pListHead;

    for(unsigned int i = 0; i < k-1; i++){
        if(fast->next != nullptr){
            fast = fast->next;
        }
        else{
            return nullptr;
        }
    }

    while(fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
