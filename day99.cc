#include <iostream>
#include <string>
#include <vector>

void strPase() {
	std::string str;
	while(std::getline(std::cin, str)) {
		std::vector<std::string> res;
		for(size_t i = 0; i < str.size();) {
			std::string tmp = "";
			if(str[i] == ' ') {
				i++;
				continue;
			} else if (str[i] == 34) {
				for(size_t j = i; str[j] != 34 && j < str.size(); j++, i++) {
					tmp.push_back(str[j]);
				}
			} else {
				for(size_t j = i; str[j] != ' ' && j < str.size(); j++, i++) {
					tmp.push_back(str[j]);
				}
			}
			res.push_back(tmp);
		}

		std::cout << res.size() << std::endl;
		for(size_t i = 0; i < res.size(); i++) {
			std::cout << res[i] << std::endl;
		}
	}
}

int main()
{
	strPase();
	// 网易动态规划
}
