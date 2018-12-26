#include <iostream>
#include <vector>

class Solution{
	public:
		void FindNumsAppearOnce(std::vector<int> data, int* num1, int *num2) {
			if(data.empty()){
				return;
			}
			int count = 0;
			for(int i = 0; i < data.size(); i++){
				count ^= data[i];
			}

			int index = 0;
			for(; index < 32; index++){
				if(count & (1 << index)){
					break;
				}
			}

			for(int i = 0; i < data.size(); i++){
				if(data[i] & (1 << index)){
					*num1 ^= data[i];
				}else{
					*num2 ^= data[i];
				}
			}
		}
};
