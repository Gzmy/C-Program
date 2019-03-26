#include <iostream>
#include <string>
#include <algorithm>

// 大数相加

std::string addStr(std::string s1, std::string s2) {
	int i = s1.size() - 1;
	int j = s2.size() - 1;
	std::string res = "";

	// 当前位相加结果
	int cur = 0;
	while(i >= 0 || j >= 0) {
		if(i >= 0) {
			cur += s1[i] - '0';
		}
		if(j >= 0) {
			cur += s2[j] - '0';
		}
		char ch = cur%10 + '0';
		res.push_back(ch);

		cur /= 10;
		i--, j--;
	}

	if(cur == 1) {
		res.push_back('1');
	}
	std::reverse(res.begin(), res.end());

	return res;
}


int main()
{
	std::string str1, str2;
	while(std::cin >> str1 >> str2) {
		std::cout << addStr(str1, str2) << std::endl;
	}
	return 0;
}
