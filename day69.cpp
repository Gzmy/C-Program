#include <iostream>
#include <vector>

class Solutione{
	public:
		//滑动窗口的最大值
		std::vector<int> maxInWindows(const std::vector<int>& num, unsigned int size){
			std::vector<int> vec;
			if(num.empty() || size == 0){
				return vec;
			}

			int max;
			for(int i = 0; i < num.size()-size+1; i++){
				max = num[i];
				for(int j = i+1; j < i+size; j++){
					if(max < num[j]){
						max = num[j];
					}
				}
				vec.push_back(max);
			}

			return vec;
		}
};
