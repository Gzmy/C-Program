#include <iostream>
#include <vector>

class Solution{
	public:
		std::vector<int> multiply(const std::vector<int>& A) {
			std::vector<int> B;
			if(A.empty()){
				return B;
			}
			B.push_back(1);
			for(int i = 0; i < A.size()-1; i++){
				B.push_back(B.back * A[i]);
			}
			int tmp = 1;
			for(int i = A.size()-1; i >= 0; i--){
				B[i] = B[i] * tmp;
				tmp *= A[i];
			}
			return B;
		}
};
