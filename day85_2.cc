#include <iostream>
#include <vector>
#include <string>


std::string longestCommonPrefix(std::vector<std::string>& strs) {
	std::string res;

	std::string tmp = strs[0];
	int maxIndex = tmp.size();

	for(size_t i = 1; i < strs.size(); i++) {
		int index = 0;
		while(tmp[index] != '\0' && strs[i][index] != '\0' && tmp[index] == strs[i][index]) {
			index++;
		}

		if(index <= maxIndex) {
			maxIndex = index;
		}
	}

	if(maxIndex <= 0) {
		return res;
	}

	return strs[0].substr(0, maxIndex);
}

int main()
{
	std::vector<std::string> vec;
	vec.push_back("aa");
	vec.push_back("a");

	std::cout << longestCommonPrefix(vec).c_str() << std::endl;
	return 0;
}
