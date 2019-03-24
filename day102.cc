#include <iostream>
#include <string>

// 统计兔子个数

void statRabbit() {
	int month;
	while(std::cin >> month) {
		int first = 1;
		int second = 1;
		int result;
		for(int i = 3; i <= month; i++) {
			result = first + second;
			first = second;
			second = result;
		}
		std::cout << result << std::endl;
	}
}

// 字符串统配,使用动态规划

bool match(const char* pattern, const char* str) {
	if(*pattern == '\0' && *str == '\0') {
		return true;
	}

	if(*pattern == '\0' || *str == '\0') {
		return false;
	}

	if(*pattern == '?') {
		return match(pattern+1, str+1);
	} else if (*pattern == '*') {
		return match(pattern+1, str) || match(pattern+1, str+1) || match(pattern, str+1);
	} else if (*pattern == *str) {
		return match(pattern+1, str+1);
	}
	return false;
}

void parseStr() {
	std::string pattern, str;
	while(std::cin >> pattern >> str) {
		if(match(pattern.c_str(), str.c_str())) {
			std::cout << "true" << std::endl;
		} else {
			std::cout << "false" << std::endl;
		}
	}
}

int main()
{
	//statRabbit() ;
	parseStr();
	return 0;
}
