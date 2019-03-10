#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	int m, n;
	std::string res, table = "0123456789ABCDEF";
	bool flag = false;
	std::cin >> m >> n;

	if(m < 0) {
		flag = true;
		m = 0 - m;
	}

	while(m) {
		res += table[m%n];
		m /= n;
	}

	if(flag) {
		res += '-';
	}

	std::reverse(res.begin(), res.end());
	std::cout << res << std::endl;
	return 0;
}
