#include <iostream>
#include <vector>

class Solution{
	public:
		int FindGreatestSumOfSubArray(std::vector<int> array) {
			if(array.empty()){
				return 0;
			}

			int cur = array[0];
			int sum = array[0];
			for(int i = 1; i < array.size(); i++){
				cur += array[i];
				if(cur < array[i]){
					cur = array[i];
				}
				if(cur > sum){
					sum = cur;
				}
			}

			return sum;
		}
};
