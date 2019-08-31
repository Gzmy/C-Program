#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// big add
std::string addStrings(std::string num1, std::string num2) {
	std::string res;
	int cur = 0, left = num1.size() - 1, right = num2.size() - 1;

	while(left >= 0 || right >= 0 || cur > 0) {
		cur += (left >= 0 ? num1[left--] - '0' : 0);
		cur += (right >= 0 ? num2[right--] - '0' : 0);

		res += std::to_string(cur % 10);
		cur /= 10;
	}

	std::reverse(res.begin(), res.end());
	return res;
}

std::string multiplyString(std::string num1, std::string num2) {
	if(num1 == "0" || num2 == "0") {
		return "0";
	}

	std::string res;
	int m = num1.size(), n = num2.size();
	std::vector<int> val(m + n, 0);

	for(int i = m-1; i >= 0; --i) {
		for(int j = n-1; j >= 0; --j) {
			int num = (num1[i] - '0') * (num2[j] - '0');
			int p1 = i+j, p2 = i+j+1, sum = num + val[p2];

			val[p1] += sum / 10;
			val[p2] = sum % 10;
		}
	}

	for(auto e : val) {
		if(!res.empty() || e != 0) {
			res.push_back(e + '0');
		}
	}

	return res;
}
