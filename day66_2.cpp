#include <iostream>
#include <vector>
#include <queue>
#include <functional>

class Solution{
	public:
		std::vector<int> GetLeastNumber(std::vector<int> input, int k){
			std::vector<int> vec;
			std::priority_queue<int, std::vector<int>, std::greater<int>> q;
			if(input.empty() || k > input.size()){
				return vec;
			}

			for(auto& e : input){
				q.push(e);
			}

			for(int i = 0; i < k; i++){
				vec.push_back(q.top());
				q.pop();
			}

			return vec;
		}
};
