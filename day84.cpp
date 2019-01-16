#include <iostream>
#include <limits.h>

//leetcode 7

int reverse(int x) {
	int tmp = 0;
	int res = 0;

	while(x) {
		tmp = res*10 + x%10;
		if(tmp/10 != res) {
			return 0;
		}
		res = tmp;
		x /= 10;
	}

	return res;
}

//leetcode 8
int myatoi(std::string str) {
	if(str.empty()) {
		return 0;
	}

	int i = 0;
	int res = 0, tmp = 0;
	bool isNg = false;

	while(str[i] == ' ') {
		i++;
	}

	if(str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9')){
		if(str[i] == '+') {
			i++;
		} else if(str[i] == '-') {
			i++;
			isNg = true;
		}

		while(str[i] >= '0' && str[i] <= '9') {
			tmp = res*10 + (str[i]-'0');
			if(tmp/10 != res) {
				if(isNg) {
					return INT_MIN;
				} else {
					return INT_MAX;
				}
			}
			res = tmp;
			i++;
		}

	} else {
		return 0;
	}

	if(isNg) {
		return 0-res;
	}
	return res;
}
