#include <iostream>
#include <vector>

class Solution{
	public:
		int movingCount(int threshold, int rows, int cols){
			std::vector<std::vector<int> > vec(rows+1);
			for(int i = 0; i < rows+1; i++){
				vec[i].resize(cols+1, 0);
			}
			return flag(0, 0, rows, cols, vec, threshold);
		}

		int getSum(int num){
			int count = 0;
			while(num){
				count += num%10;
				num /= 10;
			}
			return count;
		}
	private:
		int flag(int i, int j, int rows, int cols, std::vector<std::vector<int> > &vec, int threshold){
			if(i < 0 || i >= rows || j < 0 || j >= cols || getSum(i) + getSum(j) > threshold || vec[i][j] == 1){
				return 0;
			}
			vec[i][j] = 1;

			return flag(i+1, j, rows, cols, vec, threshold) +
				flag(i-1, j, rows, cols, vec, threshold) +
				flag(i, j+1, rows, cols, vec, threshold) +
				flag(i, j-1, rows, cols, vec, threshold) + 1;
		}
};
