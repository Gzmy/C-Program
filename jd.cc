#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// https://www.nowcoder.com/test/16778489/summary 
//
// 1. 寻找子串
// 给出m个字符串S1，S2，...，Sm和一个单独的字符串T。请在T中选出尽可能多的子串同时满足：  
// 1）这些子串在T中互不相交。
// 2）这些子串都是S1，S2，...，Sm中的某个串。  问最多能选出多少个子串。
//
// input: 
//		3
//		aa
//		b
//		ac
//		bbaac
// output:
//		3

bool cmp(const std::string& s1, const std::string& s2) {
	return s1.size() < s2.size();
}

void searchStr() {
	int num;
	while(std::cin >> num) {
		std::vector<std::string> vec(num);
		for(int i = 0; i < num; ++i) {
			std::cin >> vec[i];
		}
		std::string src;
		std::cin >> src;

		std::sort(vec.begin(), vec.end(), cmp);
		int res = 0;
		for(auto it = vec.begin(); it !=  vec.end(); ++it) {
			size_t pos = 0;
			while((pos = src.find(*it, pos)) != src.npos) {
				++res;
				src.replace(pos, it->size(), "0");
			}
		}

		std::cout << res << std::endl;
	}
}

// 体育场突然着火了，现场需要紧急疏散，但是过道真的是太窄了，同时只能容许一个人通过。
// 现在知道了体育场的所有座位分布，座位分布图是一棵树，已知每个座位上都坐了一个人，
// 安全出口在树的根部，也就是1号结点的位置上。其他节点上的人每秒都能向树根部前进一个结点，
// 但是除了安全出口以外，没有任何一个结点可以同时容纳两个及以上的人，
// 这就需要一种策略，来使得人群尽快疏散，问在采取最优策略的情况下，
// 体育场最快可以在多长时间内疏散完成。
//
// input: 
//		6
//		2 1
//		3 2
//		4 3
//		5 2
//		6 1
// output:
//		4



