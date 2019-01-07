#include <iostream>
#include <vector>

class Solution{
	//矩阵中的路径
	public:
		bool hasPath(char* matrix, int rows, int cols, char* str){
			std::vector<char> vec(rows*cols, 0);
			bool condition = false;
			for(int i = 0; i < rows; i++){
				for(int j = 0; j < cols; j++){
					condition = (condition || isPath(matrix, vec, str, i, j, rows, cols));
				}
			}
			return condition;
		}
	private:
		bool isPath(char *matrix, std::vector<char> vec, char *str, int x, int y, int rows, int cols){
			if(x < 0 || x > rows || y < 0 || y > cols){
				return false;
			}

			if(matrix[x*cols+y] == *str && vec[x*cols+y] == 0){
				vec[x*cols+y] = 1;

				if(*(str+1) == 0){
					return true;
				}

				bool condition = isPath(matrix, vec, (str+1), x, y-1, rows, cols) || 
					isPath(matrix, vec, (str+1), x-1, y, rows, cols) ||
					isPath(matrix, vec, (str+1), x, y+1, rows, cols) || 
					isPath(matrix, vec, (str+1), x+1, y, rows, cols);

				if(!condition){
					vec[x*cols+y] = 0;
				}
				return condition;
			}else{
				return false;
			}
		}
};
