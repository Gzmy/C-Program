#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

// 不处理输入输出
// 一个数组有 N 个元素，求连续子数组的最大和。 
// 例如：[-1,2,1]，和最大的连续子数组为[2,1]，其和为 3

int getSum(std::vector<int>& vec) {
	int res = vec[0], cur = vec[0];

	for(size_t i = 1; i < vec.size(); ++i) {
		cur = cur < 0 ? vec[i] : cur + vec[i];
		res = std::max(res, cur);
	}

	return res;
}

// 输入一个正整数n,求n!(即阶乘)末尾有多少个0？ 
// 比如: n = 10; n! = 3628800,所以答案为2

int getZero(int num) {
	int res = 0;

	for(int i = 5; i <= num; i *= 5) {
		res += (num/i);
	}

	return res;
}

// 给定一个十进制数M，以及需要转换的进制数N。
// 将十进制数M转化为N进制数
// 2 <= target <= 16
void conversionN(int num, int target) {
	std::string res, table = "0123456789ABCDEF";
	while(num) {
		if(num < 0) {
			num = 0 - num;
			std::cout << "-";
		}
		res = table[num%target] + res;
		num /= target;
	}
	std::cout << res << std::endl;
}

// 给定一个有n个正整数的数组A和一个整数sum,
// 求选择数组A中部分数字和为sum的方案数。
// 当两种选取方案有一个数字的下标不一样
// 我们就认为是不同的组成方案。

int getWay(std::vector<int>& vec, int target) {
	// dp[i][j] 表示用前 i 个值组成和为 j 的方案数
	int size = vec.size();
	std::vector<std::vector<long>> dp(size+1, std::vector<long>(target+1, 0));
	dp[0][0] = 1;

	for(int i = 1; i <= size; ++i) {
		for(int j = 0; j <= target; ++j) {
			dp[i][j] = dp[i-1][j];
			if(j >= vec[i-1]) {
				dp[i][j] += dp[i-1][j-vec[i-1]];
			}
		}
	}

	return dp[size][target];
}

// 某餐馆有n张桌子，每张桌子有一个参数：a 可容纳的最大人数； 
// 有m批客人，每批客人有两个参数:b人数，c预计消费金额。 
// 在不允许拼桌的情况下，请实现一个算法选择其中一部分客人，使得总预计消费金额最大

bool cmp(std::pair<int, int>& p1, std::pair<int, int>& p2) {
	return p1.second > p2.second;
}

int getMaxCom() {
	int n, m;
	std::cin >> n >> m;
	std::multiset<int> desk;
	for(int i = 0; i < n; ++i) {
		int tmp; 
		std::cin >> tmp;
		desk.insert(tmp);
	}

	std::vector<std::pair<int, int>> custom(m);
	for(int i = 0; i < m; ++i) {
		std::cin >> custom[i].first >> custom[i].second;
	}

	std::sort(custom.begin(), custom.end(), cmp);
	int res = 0;

	for(auto& it : custom) {
		auto pos = desk.lower_bound(it.first);
		if(pos != desk.end()) {
			desk.erase(pos);
			res += it.second;
		}
	}

	return res;
}

int main()
{
    int num, target;
    while(std::cin >> num >> target) {
        std::vector<int> vec(num);
        for(int i = 0; i < num; ++i) {
            std::cin >> vec[i];
        }
        
        std::cout << getWay(vec, target) << std::endl;
    }
    return 0;
}
