#include <iostream>
#include <vector>

int main()
{
	int n;
	while(std::cin >> n) {
		std::vector<int> vec(n);
		for(int i = 0; i < n; i++) {
			std::cin >> vec[i];
		}
		int res = 1;
		std::vector<int> dp(n, 1);

		for(int i = 1; i < n; i++) {
			for(int j  = 0; j < i; j++) {
				if(vec[j] < vec[i]) {
					dp[i] = std::max(dp[i], dp[j] + 1);
				}
			}
			res = std::max(dp[i], res);
		}
		std::cout << res << std::endl;
	}
	return 0;
}
