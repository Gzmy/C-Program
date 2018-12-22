#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution{
	public:
		std::vector<std::string> result;
		std::vector<std::string> Permutation(std::string str){
			if(str.size() == 0){
				return result;
			}
			Permutation1(str, 0);
			std::sort(result.begin(), result.end());
			return result;
		}

		void Permutation1(std::string str, int begin){
			if(str.size() == begin){
				result.push_back(str);
				return;
			}

			for(int i = begin; str[i] != '\0'; i++){
				if(i != begin && str[begin] == str[i])
					continue;
				std::swap(str[begin], str[i]);
				Permutation1(str, begin+1);
				std::swap(str[begin], str[i]);
			}
		}
};
