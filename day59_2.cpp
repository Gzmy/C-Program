#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//栈的压入、弹出序列
class Solution{
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV){
        stack<int> stackData;
        int id = 0;
        unsigned long i = 0;
        for(; i < popV.size(); i++){
            while(stackData.empty() || stackData.top() != popV[i]){
                stackData.push(pushV[id++]);
            }
            if(stackData.top() == popV[i]){
                stackData.pop();
            }
        }

        if(stackData.empty()){
            return true;
        }else{
            return false;
        }
    }

    //丑数
    int GetUglyNumber(int index){
        if(index < 7){
            return index;
        }

        int p2 = 0, p3 = 0, p5 = 0, newNum = 1;
        vector<int> vec;
        vec.push_back(newNum);
        while(vec.size() < index){
            newNum = min(vec[p2] * 2, min(vec[p3] * 3, vec[p5] * 5));
            if(vec[p2] * 2 == newNum){
                p2++;
            }
            if(vec[p3] * 3 == newNum){
                p3++;
            }
            if(vec[p5] * 5 == newNum){
                p5++;
            }
            vec.push_back(newNum);
        }

        return newNum;
    }
};
