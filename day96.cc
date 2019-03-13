#include <iostream>
#include <string>
#include <vector>
#include <string.h>

bool isDict(const std::vector<std::string>& vec) {
	for(size_t i = 0; i < vec.size()-1; i++) {
		if(strcmp(vec[i+1].c_str(), vec[i].c_str()) < 0) {
			return false;
		}
	}
	return true;
}

bool isLength(const std::vector<std::string>& vec) {
	for(size_t i = 0; i < vec.size()-1; i++) {
		if(vec[i+1].size() < vec[i].size()) {
			return false;
		}
	}
	return true;
}


void dictOrLength() {
	int n;
	std::cin >> n;
	std::vector<std::string> vec(n);
	for(int i = 0; i < n; i++) {
		std::cin >> vec[i];
	}

	bool dict = isDict(vec);
	bool length = isLength(vec);

	if(dict && length) {
		std::cout << "both" << std::endl;
	} else if(dict && !length) {
		std::cout << "lexicographically" << std::endl;
	} else if(!dict && length) {
		std::cout << "lengths" << std::endl;
	} else {
		std::cout << "none" << std::endl;
	}
}

//求小公倍数
//最小公倍数 = 两数相乘除以最大公约数

int gcb(int a, int b) { //辗转相除法
	int r;
	while(r = a%b) {
		a = b;
		b = r;
	}
	return b;
}

void findMinNum() {
	int a, b;
	while(std::cin >> a >> b) {
		std::cout << a * b / gcb(a, b) << std::endl;
	}
}

int main()
{
	findMinNum();
	return 0;
}
