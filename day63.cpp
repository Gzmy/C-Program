#include <iostream>
#include <vector>
#include <queue>

//数组中的第K个最大元素
int findKthLargest(std::vector<int>& nums, int k) {
    if(nums.size() == 0){
        return -1;
    }

    std::priority_queue<int> q(nums.begin(), nums.end());

    for(int i = 0; i < k - 1; i++){
        q.pop();
    }

    return q.top();
}
