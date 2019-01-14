#include <iostream>
#include <vector>
#include <string>
#include <map>

//leetcode 692
class Solution{
	public:
		std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k) {
			std::vector<std::string> vec;
			if(words.empty() || k <= 0) {
				return vec;
			}

			std::map<std::string, int> countmap;
			for(size_t i = 0; i < words.size(); i++) {
				++countmap[words[i]];
			}

			std::multimap<int, std::string, std::greater<int>> sortmap;
			for(auto &countkv : countmap) {
				sortmap.insert(std::make_pair(countkv.second, countkv.first));
			}


			auto it = sortmap.begin();
			while(it != sortmap.end()) {
				if(k > 0) {
					vec.push_back(it->second);
				} else {
					break;
				}

				it++, k--;
			}
			return vec;
		}
};
