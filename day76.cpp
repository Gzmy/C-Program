#include <iostream>
#include <vector>

//
class Solution{
	public:
		//和为S的两个数字
		std::vector<int> FindNumbersWithSum(std::vector<int> array,int sum) {
			std::vector<int> vec;
			if(array.empty() || sum == 0){
				return vec;
			}

			int begin = 0, end = array.size()-1;
			int Sum = 0;
			while(begin < end){
				Sum = array[begin] + array[end];
				if(Sum > sum){
					end--;
				}else if(Sum < sum){
					begin++;
				}else{
					vec.push_back(array[begin]);
					vec.push_back(array[end]);
					break;
				}
			}

			return vec;
		}

		//和为S的连续正数序列
		std::vector<std::vector<int> > FindContinuousSequence(int sum) {
			std::vector<std::vector<int> > vec;
			if(sum == 0){
				return vec;
			}

			int fast = 2, slow = 1;
			while(slow < fast){
				int Sum = (fast + slow) * (fast - slow + 1) / 2;
				if(Sum < sum){
					fast++;
				}else if(Sum > sum){
					slow++;
				}else{
					std::vector<int> tmp;
					for(int i = slow; i <= fast; i++){
						tmp.push_back(i);
					}
					vec.push_back(tmp);
					slow++;
				}
			}

			return vec;
		}
};
