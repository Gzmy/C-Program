#include <iostream>
#include <vector>
#include <map>

int maxArea(std::vector<int>& vec) {
	if(vec.empty()) {
		return 0;
	}

	int maxCount = 0;
	int leftIndex = 0, rightIndex = vec.size()-1;

	while(leftIndex < rightIndex) {
		int tmpCount = (vec[leftIndex] < vec[rightIndex] ? \
				vec[leftIndex] : vec[rightIndex]) * (rightIndex - leftIndex);

		if(tmpCount > maxCount) {
			maxCount = tmpCount;
		}

		if(vec[leftIndex] < vec[rightIndex]) {
			leftIndex++;
		} else {
			rightIndex--;
		}
	}

	return maxCount;
}

/*
int maxArea(std::vector<int>& vec) {
	std::map<int, int> maxSize;
	int maxCount = 0;

	for(int i = 1; i <= vec.size(); i++) {
		maxSize.insert(std::make_pair(i-1, vec[i-1]));
	}

	for(int i = 0; i < vec.size(); i++) {
		for(int j = vec.size()-1; j >= 0; j--) {
			int tmpCount = (j-i) * (maxSize[i] < maxSize[j] ? maxSize[i] : maxSize[j]);

			if(tmpCount > maxCount) {
				maxCount = tmpCount;
			}
		}
	}

	return maxCount;
}
*/

int main()
{
	int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	std::vector<int> vec(arr, arr+sizeof(arr)/sizeof(arr[0]));

	std::cout << maxArea(vec) << std::endl;
	return 0;
}
