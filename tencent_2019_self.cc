// 亲身经历的腾讯笔试题
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>

// 1. 组合硬币
void coinCombin() {
	int m, n;
	while(std::cin >> m >> n) {
		std::vector<int> vec(n);
		for(int i = 0; i < n; i++) {
			std::cin >> vec[i];
		}
		std::sort(vec.begin(), vec.end());
		int num = 0, index = m;
		while(index > 0) {
			int cur;
			int minIndex = index;
			for(int i = 0; i < n; i++) {
				cur = vec[i];
				int flag;
				if(vec[i] <= index) {
					if(cur-1 > index-cur) {
						flag = cur-1;
					}
				}
			}
		}
	}
}

// 2. 01字符

void minZeroOneChar() {
	std::string str;
	while(std::getline(std::cin, str)) {
		int zeroNum = 0, oneNum = 0;
		for(size_t i = 0; i < str.size(); i++) {
			if(str[i] == '0') {
				zeroNum++;
			} else {
				oneNum++;
			}
		}

		std::cout << abs(zeroNum-oneNum) << std::endl;
	}
}

// 3. 打怪升级


int main()
{
	minZeroOneChar();
	return 0;
}
