#include <iostream>
#include <vector>

//二插搜素树的后序遍历
class Solution{
	public:
	static bool VerifySquenceOfBST(std::vector<int> sequence){
			int size = sequence.size();
			if(size == 0){
				return false;
			}

			int i = 0;
			while(--size){
				while(sequence[i++] < sequence[size]);
				while(sequence[i++] > sequence[size]);

				if(i < size){
					return false;
				}
				i = 0;
			}

			return true;
		}
};

int main()
{
	int array1[] = {5, 7, 6, 9, 11, 10, 8};
	int array2[] = {7, 4, 6, 5};
	std::vector<int> vec1(array1, array1 + sizeof(array1)/sizeof(array1[0]));
	std::vector<int> vec2(array2, array2 + sizeof(array2)/sizeof(array2[0]));

	if(Solution::VerifySquenceOfBST(vec1)){
		std::cout << "one plus" << std::endl;
	}

	if(Solution::VerifySquenceOfBST(vec2)){
		std::cout << "two plus" << std::endl;
	}

	return 0;
}

