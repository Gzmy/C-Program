#include <iostream>
#include <limits.h>
#include <vector>

//leetcode 76. Minimum Window Substring
std::string minWindow(std::string s, std::string t) {
	std::string str;
	if(s.size() < t.size()) {
		return str;
	}

	std::vector<int> vec(256, 0);
	int minIndex = 0, max = INT_MAX;
	int count = 0;
	for(char c : t) {
		vec[c]++;
	}

	for(size_t i = 0; i < s.size(); i++) {
		if(--vec[s[i]] >= 0) { //说明s中有t的字符
			count++;
		}

		while(count == t.size()) {
			if(max > i-minIndex+1) {
				max = i-minIndex+1;
				str = s.substr(minIndex, max);
			}

			if(++vec[s[i]] > 0) {
				count--;
			}

			minIndex++;
		}
	}

	return str;
}

//209. Minimum Size Subarray Sum
int minSubArrayLen(int s, std::vector<int>& nums) {
	if(nums.empty()) {
		return 0;
	}

	int minIndex = 0, maxIndex = -1;
	int count = nums.size()+1;
	int sum = 0;

	while(minIndex < nums.size()) {
		if(sum < s && maxIndex + 1 < nums.size()) {
			maxIndex++;
			sum += nums[maxIndex];
		} else {
			sum -= nums[minIndex];
			minIndex--;
		}

		if(sum >= s) {
			if(count > maxIndex-minIndex+1) {
				count = maxIndex-minIndex+1;
			}
		}
	}
	
	if(count == nums.size() + 1) {
		return 0;
	}
	return count;
}
