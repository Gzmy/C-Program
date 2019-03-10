#include <iostream>
#include <vector>
#include <string>

bool isCirleText(const std::string& str) {
	int left = 0;
	int right = str.size()-1;
	while(left < right) {
		if(str[left] != str[right]) {
			return false;
		}
		left++, right--;
	}
	return true;
}

//统计回文
void countText() {
	std::string A, B;
	std::getline(std::cin, A);
	std::getline(std::cin, B);
	int count = 0;

	for(size_t i = 0; i < A.size(); i++) {
		std::string str = A;
		str.insert(i, B);
		if(isCirleText(str)) {
			count++;
		}
	}

	std::cout << count << std::endl;
}

//连续子数组的最大和
int main()
{
	countText();
//	int n;
//	std::cin >> n;
//	std::vector<int> vec(n);
//	for(int i = 0; i < n; i++) {
//		std::cin >> vec[i];
//	}
//
//	int sum = vec[0];
//	int res = vec[0];
//	for(int i = 1; i < n; i++) {
//		sum += vec[i];
//		if(sum < vec[i]) {
//			sum = vec[i];
//		}
//		if(res < sum) {
//			res = sum;
//		}
//	}
//
//	std::cout << res << std::endl;
	return 0;
}
