#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

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
//
//void factor(int n, std::vector<int>& vec) {
//	for(int i = 2; i <= sqrt(n); i++) {
//		if(n%i == 0) {
//			vec.push_back(i);
//			if(n/i != i) {
//				vec.push_back(n/i);
//			}
//		}
//	}
//}
//
//void jumpSlate() {
//	int n, m;
//	std::cin >> n >> m; 
//	std::vector<int> stepNum(m+1, 0);
//	std::vector<int> divNum;
//	stepNum[n] = 1;
//	for(int i = n; i <= m; i++) {
//		if(stepNum[i] == 0) {
//			continue;
//		}
//		divNum.clear();
//		factor(i, divNum);
//		for(size_t j = 0; j < divNum.size(); j++) {
//			if(i+divNum[j] <= m && stepNum[i+divNum[j]] != 0) {
//				stepNum[i+divNum[j]] = std::min(stepNum[i+divNum[j]], stepNum[i]+1);
//			} else {
//				stepNum[i+divNum[j]] = stepNum[i] + 1;
//			}
//		}
//	}
//	
//	std::cout << (stepNum[m] > 0 ? stepNum[m]-1 :-1) << std::endl;
//}

int main()
{
	//strPase();
}
