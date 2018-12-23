#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
	public:
		static bool cmp(int a, int b){
			std::string A = to_string(a) + to_string(b);
			std::string B = to_string(b) + to_string(a);
			return A < B;
		}

		std::string PrintMinNumber(std::vector<int> numbers) {
			std::string str = "";
			if(numbers.empty()){
				return str;
			}
			std::sort(numbers.begin(), numbers.end(), cmp);
			for(int i = 0; i < numbers.size(); i++){
				str += to_string(numbers[i]);
			}

			return str;
		}
};
