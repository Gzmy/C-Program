#include <iostream>
#include <vector>

// 小易的升级之路 day3_28

int maxDef(int buf, int num) {
	while(buf != num) {
		if(buf > num) {
			buf -= num;
		} else {
			num -= buf;
		}
	}
	return buf;
}

int main()
{
	int num, buf;
	while(std::cin >> num >> buf) {
		std::vector<int> arr(num);
		for(int i = 0; i < num; i++) {
			std::cin >> arr[i];
		}

		for(int i = 0; i < num; i++) {
			if(buf >= arr[i]) {
				buf += arr[i];
			} else {
				buf += maxDef(buf, arr[i]);
			}
		}
		std::cout << buf << std::endl;
	}
	return 0;
}
