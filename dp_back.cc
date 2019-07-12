#include <iostream>
#include <vector>

// 现有一个容量大小为V的背包和N件物品，每件物品有两个属性，
// 体积和价值，请问这个背包最多能装价值为多少的物品？
//
// input: 
// 第一行两个整数V和n。
// 接下来n行，每行两个整数体积和价值。1≤N≤1000,1≤V≤20000。
// 每件物品的体积和价值范围在[1,500]。
//
// output:
// 输出背包最多能装的物品价值。
//
// eg: 
//
// input:
// 6 3
// 3 5
// 2 4
// 4 2
// 
// output:
// 9


// dp[][]
//int package(int pack, std::vector<int>& A, std::vector<int>& V) {
//	if(pack < 0 || A.empty() || V.empty()) {
//		return 0;
//	}
//
//	int N = A.size() + 1;
//	int M = pack + 1;
//	std::vector<std::vector<int>> dp(N, std::vector<int>(M, 0));
//
//	for(int i = 1; i < N; ++i) {
//		for(int j  = 1; j < M; ++j) {
//			if(j < V[i-1]) { // 放不下
//				dp[i][j] = dp[i-1][j];
//			} else {
//				dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-A[i-1]]+V[i-1]);
//			}
//		}
//	}
//
//	return dp[N-1][M-1];
//}

// 优化为一维空间
int package(int pack, std::vector<int>& A, std::vector<int>& V) {
	if(pack <= 0 || A.empty() || V.empty()) {
		return 0;
	}

	int N = A.size();
	int M = pack + 1;
	std::vector<int> dp(M, 0);

	for(int i = 0; i < N; ++i) {
		for(int j = M-1; j >= A[i]; --j) {
			dp[j] = std::max(dp[j], dp[j-A[i]]+V[i]);
		}
	}

	return dp[M-1];
}


int main()
{
	int v, n;
	std::cin >> v >> n;
	std::vector<int> A(n);
	std::vector<int> V(n);

	for(int i = 0; i < n; ++i) {
		std::cin >> A[i];
		std::cin >> V[i];
	}

	std::cout << package(v, A, V) << std::endl;

	//std::cout << "weight: ";
	//for(auto e : A) {
	//	std::cout << e << ", ";
	//}
	//std::cout << std::endl;

	//std::cout << "value: ";
	//for(auto e : V) {
	//	std::cout << e << ", ";
	//}
	//std::cout << std::endl;
	return 0;
}
