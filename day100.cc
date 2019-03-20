#include <iostream>
#include <vector>
#include <algorithm>

// 从当前位置开始搜索符合要求的组合，
// pos: 当前搜索的位置
// sum: 到目前位置的累加和
// mutil: 到目前位置的累加积


int getLuck(std::vector<int>& vec, int pos, int sum, int mutil) {
	int count = 0;
	for(size_t i = pos; i < vec.size(); i++) {
		sum += vec[i];
		mutil *= vec[i];
		if(sum > mutil) {
			count += getLuck(vec, i+1, sum, mutil) + 1;
		} else if (vec[i] == 1) {
			count += getLuck(vec, i+1, sum, mutil);
		} else {
			break;
		}

		sum -= vec[i];
		mutil /= vec[i];
		while(i < vec.size()-1 && vec[i] == vec[i+1]) {
			i++;
		}
	}
	return count;
}

int main()
{
	int n;
	while(std::cin >> n) {
		std::vector<int> arr(n);
		for(int i = 0; i < n; i++) {
			std::cin >> arr[i];
		}
		std::sort(arr.begin(), arr.end());
		std::cout << getLuck(arr, 0, 0, 1) << std::endl;
	}
}
