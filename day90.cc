#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>

//组队竞赛
void groupTest() {
	int n;
	while(std::cin >> n) {
		long long sum = 0;
		std::vector<int> vec(3 * n);
		for(int i = 0; i < (3*n); i++) {
			std::cin >> vec[i];
		}

		std::sort(vec.begin(), vec.end());
		for(int i = n; i <= 3*n - 2; i += 2) {
			sum += vec[i];
		}

		std::cout << sum << std::endl;
	}
}

int main()
{
	std::string str1;
	std::string str2;

	std::getline(std::cin, str1);
	std::getline(std::cin, str2);

	int arr[256] = {0};
	for(size_t i = 0; i < str2.size(); i++) {
		arr[str2[i]]++;
	}

	for(size_t i = 0; i < str1.size() ; i++) {
		if(arr[str1[i]] == 0) {
			printf("%c", str1[i]);
		}
	}
	fflush(stdout);

	return 0;
}
