#include <iostream>

class Solution{
	public:
		int NumberOf1Between1AndN_Solution(int n){
			int count = 0;
			if(n <= 0){
				return 0;
			}

			for(int i = 1; i <= n; i++){
				int tmp = i;
				while(tmp){
					if(tmp % 10 == 1){
						count++;
					}
					tmp /= 10;
				}
			}

			return count;
		}
};
