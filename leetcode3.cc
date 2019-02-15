#include <iostream>
#include <string>
#include <set>
#include <algorithm>

//无重复字符的最长子串
int lengthOfLongestSubstring(std::string s) {
	if(s.size() == 1 || s.size() == 0) {
		return s.size();
	}

	std::set<int> inputSet;
	int maxLen = 0;
	size_t index = 0;
	int leftIndex = 0;

	while(index < s.size()) {
		if(inputSet.find(s[index]) == inputSet.end()) {
			inputSet.insert(s[index++]);
			maxLen = std::max(maxLen, (int)inputSet.size());
		} else {
			inputSet.erase(s[leftIndex++]);
		}
	}

	return maxLen;
}


int main()
{
	std::cout << lengthOfLongestSubstring("bbbb") << std::endl;
}
