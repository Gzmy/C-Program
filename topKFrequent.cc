#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

// 找出数组前K个频率最大的数
std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
	std::vector<int> res;
	if(nums.empty()) {
		return res;
	}

	std::unordered_map<int, int> countMap;
	std::priority_queue<std::pair<int, int>> resQueue;

	for(size_t i = 0; i < nums.size(); ++i) {
		++countMap[nums[i]];
	}

	for(auto e : countMap) {
		resQueue.push(std::make_pair(e.second, e.first));
	}

	for(int i = 0; i < k; ++i) {
		res.push_back(resQueue.top().second);
		resQueue.pop();
	}
	return res;
}
