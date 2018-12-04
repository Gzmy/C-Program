#include <iostream>
using namespace std;

class Solution{
public:
    //二维数组中的查找
    bool Find(int target, vector<vector<int>> arr)
    {
        if(arr.empty()){
            return false;
        }

        int x = 0;
        int y = arr[0].size() - 1;

        while(x <= arr.size()-1 && y >= 0){
            if(arr[x][y] == target){
                return true;
            }
            if(arr[x][y] > target){
                y--;
            }else{
                x++;
            }
        }

        return false;
    }

    //从尾到头打印链表
    vector<int> printListFrontToHead(ListNode *head)
    {
        vector<int> vec;
        if(head = =NULL){
            return vec;
        }

        while(head){
            vec.insert(vec.begin(), head->val);
            head = head->next;
        }

        return vec;
    }

    //旋转数组的最小数字
    int minNumberInrotateArray(vector<int> arr){
        if(arr.size() == 0){
            return 0;
        }

        int index1 = 0;
        int index2 = arr.size() - 1;
        int indexMid = index1;
        while(arr[index1] >= arr[index2]){
            if(index2 - index1 == 1){
                indexMid = index2;
                break;
            }

            int indexMid = (index1 + index2) / 2;
            if(arr[index1] <= arr[indexMid])
                index1 = indexMid;
            if(arr[index2] >= arr[indexMid])
                index2 = indexMid;
        }

        return arr[indexMid];
    }
};

//用两个栈实现队列
class twoStackToQueue{
public:
    void push(int node)
    {
        stack1.push(node);
    }

    int pop()
    {
        if(stack2.size() <= 0){
            while(stack1.size() > 0){
                int tmp = stack1.top();
                stack1.pop();
                stack2.push(tmp);
            }
        }

        int data = stack2.top();
        stack2.pop();
        return data;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};
