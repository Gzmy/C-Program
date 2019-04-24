#include <iostream>
#include <vector>

// https://www.nowcoder.com/questionTerminal/1d18c0841e64454cbc3afaea05e2f63c
void counterFeit() { // nowcoder 假币问题
	int n;
	while(std::cin >> n) {
		if(n == 0) {
			break;
		}
		int res = 0;
		while(n >= 2) {
			if(n%3) {
				n = n/3 + 1;
			} else {
				n /= 3;
			}
			res++;
		}
		std::cout << res << std::endl;
	}
}

// https://www.nowcoder.com/questionTerminal/296c2c18037843a7b719cf4c9c0144e4
// 正整数的最小不可组成和

int getFirstUnFormedNum(std::vector<int>& arr, int lenth) {
	int sum = 0, min = arr[0];
	int i, j;
	for(int i = 0; i < lenth; i++) {
		sum += arr[i];
		min = arr[i] < min ? arr[i] : min;
	}
	std::vector<int> dp(sum+1, 0);
	for(i = 0; i < lenth; i++) {
		for(j = sum; j >= arr[i]; j--) {
			if(dp[j] < dp[j - arr[i]] + arr[i]) {
				dp[j] = dp[j - arr[i]] + arr[i];
			} else {
				dp[j] = dp[j];
			}
		}
	}

	for(i = min; i <= sum; i++) {
		if(i != dp[i]) 
			return i;
	}
	return sum + 1;
}

int main()
{
	counterFeit();
	return 0;
}
