/*
 *   Definition for singly-linked list.
 *   struct ListNode {
 *         int val;
 *         struct ListNode *next;
 *     };
 *  
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL){
        return NULL;     
    }
        
    struct ListNode *Node = head;
    struct ListNode *cur = NULL;
    struct ListNode *Result = NULL;
                    
    while(Node){
        //del head
        cur = Node;
        Node = Node->next;
                                                     
        //Insert haed
        cur->next = Result;
        Result = cur;
    }
                    
   return Result;
}
