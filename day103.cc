#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

// 查找两个字符串a,b中的最长公共子串
// 动态规划

void maxStr() {
	std::string A, B;
	while(std::cin >> A >> B) {
		if(A.size() > B.size()) {
			std::swap(A, B);
		}

		int lenA = A.size(), lenB = B.size();
		int start = 0, maxIndex = 0;
		std::vector<std::vector<int> > dp(lenA+1, std::vector<int>(lenB+1, 0));
		for(int i = 1; i <= lenA; i++) {
			for(int j = 1; j <= lenB; j++) {
				if(A[i-1] == B[j-1]) {
					dp[i][j] = 1 + dp[i-1][j-1]; // 本次规划依赖于上次最优解
				}

				if(dp[i][j] > maxIndex) {
					maxIndex = dp[i][j];
					start = i-maxIndex;
				}
			}
		}
		std::cout << A.substr(start, maxIndex) << std::endl;
	}
}


// 喝饮料
void drinkVec() {
	int n;
	while(std::cin >> n) {
		std::cout << n/2 << std::endl;
	}
}

int main()
{
	maxStr();
	//drinkVec();
	return 0;
}
