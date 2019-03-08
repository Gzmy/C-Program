#include <iostream>
#include <string>
#include <vector>

// 3_6
int main()
{
	std::string str, res, cur;
	std::cin >> str;
	for(size_t i = 0; i <= str.size(); i++) {
		if(str[i] >= '0' && str[i] <= '9') {
			cur += str[i];
		} else {
			if(res.size() < cur.size()) {
				res = cur;
			} else {
				cur.clear();
			}
		}
	}
	std::cout << res;
	return 0;
}

void findHalfNum() {
	int count[100] = {0};
	int x = 0, n = 0;
	while(std::cin >> x) {
		count[x]++;
		n++;
	}

	for(int i = 0; i < n; i++) {
		if(count[i] >= n/2) {
			std::cout << i << std::endl;
		}
	}
}
