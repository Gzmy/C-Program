#include <iostream>
#include <vector>

class Solution{
	public:
		int GetUglyNumber_Solution(int index) {
			if(index < 7){
				return index;
			}

			std::vector<int> vec(index);
			vec[0] = 1;
			int d2 = 0, d3 = 0, d5 = 0, i;
			for(i = 1; i < index; i++){
				vec[i] = std::min(vec[d2]*2, std::min(vec[d3]*3, vec[d5]*5));
				if(vec[i] == vec[d2]){
					d2++;
				}
				if(vec[i] == vec[d3]){
					d3++;
				}
				if(vec[i] == vec[d5]){
					d5++;
				}
			}

			return vec[index - 1];
		}
};
