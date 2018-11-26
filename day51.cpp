#include <iostream>
using namespace std;

//将一个字符串转换为一个整数
class Solution{
public:
    int strToInt(string str)
    {
        int len = str.length();
        int i = 0, sum = 0;
        bool fu = true;
        while(str[i] == ' '){
            i++;
        }

        if(str[i] == '-'){
            fu = false;
            i++;
        }
        else if(str[i] == '+'){
            i++;
        }

        while(i < len){
            if(str[i] >= '0' && str[i] <= '9'){
                sum = sum*10 + str[i]-'0';
                i++;
            }else{
                break;
            }
        }

        if(i < len){
            return 0;
        }
        if(fu == false){
            return 0-sum;
        }
        return sum;
    }
};

//复杂链表的复制
class Solution{
public:
    RandomListNode *__createNode(int data)
    {
        RandomListNode *pNewNode = (RandomListNode*)malloc(sizeof(RandomListNode));
        pNewNode->label = data;
        pNewNode->next = NULL;
        pNewNode->random = NULL;

        return pNewNode;
    }

    RandomListNode *Clone(RandomListNode *pHead)
    {
        if(pHead == NULL){
            return NULL;
        }

        RandomListNode *node = pHead;
        RandomListNode *newNode = NULL;
        RandomListNode *cur = NULL;
        RandomListNode *tmp = NULL;

        //copy after
        while(node){
            newNode = __createNode(node->label);
            newNode->next = node->next;
            node->next = newNode;
            node = newNode->next;
        }

        //copy random
        node = pHead;
        while(node){
            if(node->random != NULL){
                node->next->random = node->random->next;
            }
            node = node->next->next;
        }

        //duna
        node = pHead;
        cur = tmp = node->next;
        node->next = tmp->next;
        node = node->next;

        while(node){
            tmp->next = node->next;
            tmp = tmp->next;
            node->next = tmp->next;
            node = node->next;
        }
        return cur;
    }
};
