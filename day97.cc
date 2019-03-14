#include <iostream>
#include <string>

// 3_14



// 密码强度
int numSource(const std::string& str) {
	if(str.size() <= 4) {
		return 5;
	} else if(str.size() >= 5 && str.size() <= 7) {
		return 10;
	} else if(str.size() >= 8) {
		return 25;
	} else {
		return 0;
	}
}

int strAndNumCharSource(const std::string& str) {
	bool allNum = true;
	bool allSmallChar = true;
	bool allBigChar = true;
	int num = 0, charNum = 0;
	int source = 0;

	for(size_t i = 0; i < str.size(); i++) {
		if(str[i] >= '0' && str[i] <= '9') {
			num++;
		}

		if((str[i] >= 0x21 && str[i] <= 0x2F) || (str[i] >= 0x3A && str[i] <= 0x40) 
				|| (str[i] >= 0x5B && str[i] <= 0x60) || (str[i] >= 0x7B && str[i] <= 0x7E)) {
			charNum++;
		}

		if(str[i] >= 'a' && str[i] <= 'z') {
			allBigChar = false;
			allNum = false;
		}

		if(str[i] >= 'A' && str[i] <= 'Z') {
			allSmallChar = false;
			allNum = false;
		}
	}

	if(allNum) {
		source += 0;
	} else if(allSmallChar || allBigChar) {
		source += 10;
	} else if(!allSmallChar && !allBigChar) {
		source += 20;
	}

	if(num == 0) {
		source += 0;
	} else if(num == 1) {
		source += 10;
	} else if(num > 1) {
		source += 20;
	}

	if(charNum == 0) {
		source += 0;
	} else if(charNum == 1) {
		source += 10;
	} else {
		source += 25;
	}

	if(num != 0 && !allNum) {
		source += 2;
	} else if (!allNum && num != 0 && charNum != 0) {
		source += 3;
	} else if(!allSmallChar && !allBigChar && num != 0 && charNum != 0) {
		source += 5;
	}

	return source;
}

int main()
{
	std::string str;
	while(std::getline(std::cin, str)) {
		if(str.empty()) {
			std::cout << "VERY_WEAK" << std::endl;
			continue;
		}

		int source = 0;

		source += numSource(str);

		source += strAndNumCharSource(str);

		if(source >= 90) {
			std::cout << "VERY_SECURE" << std::endl;
		} else if (source >= 80) {
			std::cout << "SECURE" << std::endl;
		} else if (source >= 70) {
			std::cout << "VERY_STRONG" << std::endl;
		} else if (source >= 60) {
			std::cout << "STRONG" << std::endl;
		} else if (source >= 50) {
			std::cout << "AVERAGE" << std::endl;
		} else if (source >= 25) {
			std::cout << "WEAK" << std::endl;
		} else {
			std::cout << "VERY_WEAK" << std::endl;
		}

		str.clear();
	}
	return 0;
}
