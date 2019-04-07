// 亲身经历的腾讯笔试题
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

// 1. 组合硬币


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
