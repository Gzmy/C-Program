/*
 *  struct ListNode {
 *      int val;
 *      struct ListNode *next;
 *      ListNode(int x) : val(x), next(NULL) {};
 *  }
 */
#include <iostream>
using namespace std;

class Solution{
public:
    ListNode *mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.size() == 0){
            return NULL;
        }

        int size = lists.size();
        while(size > 1){
            int n = (size+1) / 2;
            int i = 0;
            for(; i < size/2; i++){
                lists[i] = mergeList(lists[i], lists[i+n]);
            }
            size = n;
        }

        return lists[0];
    }

    ListNode *mergeList(ListNode *l1, ListNode *l2)
    {
        ListNode *pHead = new ListNode(0);
        ListNode *node = pHead;

        while(l1 && l2){
            if(l1->val < l2->val){
                node->next = l1;
                l1 = l1->next;
            }else{
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }

        if(l1){
            node->next = l1;
        }
        if(l2){
            node->next = l2;
        }

        return pHead->next;
    }

    // 无重复字符的最长子串
    int lengthOfLongestSubstring(string s)
    {
        if(s.size() == 1 || s.size() == 0){
            return s.size();
        }

        int curLength = 0;
        int maxLength = 0;
        
        int *arr = new int[26];
        int i = 0;
        for(; i < 26; i++){
            arr[i] = -1;
        }

        for(i = 0; i < s.size(); i++){
            int preIndex = arr[s[i] - 'a'];
            if(preIndex < 0 || i - preIndex > curLength){
                curLength++;
            }
            else{
                if(curLength > maxLength){
                    maxLength = curLength;
                }
                curLength = i - preIndex;
            }
            arr[s[i] - 'a'] = i;
        }

        if(curLength > maxLength){
            maxLength = curLength;
        }

        delete[] arr;
        return maxLength;
    }
};
