#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

//day 3_5

bool isNum(char c) {
	if(c >= '0' && c <= '9') {
		return true;	
	}
	return false;
}

int main()
{
	std::string s;
	std::getline(std::cin, s);

	int index = 0, len = 0;
	int max = 0;
	for(size_t i = 0; i < s.size(); i++) {
		if(isNum(s[i])) {
			len++;
		}

		if(isNum(s[i]) && !isNum(s[i+1])) {
			if(len > max) {
				max = len;
				index = i - len + 1;
			}
			len = 0;
		}
	}

	std::cout << s.substr(index, max) << std::endl;
	return 0;
}


void halfOfnum() {
	std::string s, res;
	std::getline(std::cin, s);
	for(size_t i = 0; i < s.size(); i++) {
		if(s[i] != ' ') {
			res += s[i];
		}
	}

	std::vector<int> count(256);
	for(size_t i = 0; i < res.size(); i++) {
		count[res[i]]++;
	}

	for(size_t i = 0; i < count.size(); i++) {
		if(count[i] >= res.size()/2) {
			printf("%c\n", i);
		}
	}
}
