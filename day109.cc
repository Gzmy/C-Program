#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

// 使用set记录连接和未连接对象, 并每次更新最大值

void sqlConPoll() {
	int n;
	while(std::cin >> n) {
		std::set<std::string> pool;
		int maxSize = 0;
		std::string id, con;
		for(int i = 0; i < n; i++) {
			std::cin >> id >> con;
			if(con == "connect") {
				pool.insert(id);
			} else {
				pool.erase(id);
			}
			int size = pool.size();
			maxSize = std::max(maxSize, size);
		}

		std::cout << maxSize << std::endl;
	}
}

// 使用辅助空间标记是否可以打印, 判断前一个与现在的关系

void mkdir_p() {
	int n;
	while(std::cin >> n) {
		std::vector<std::string> vec(n);
		for(int i = 0; i < n; i++) {
			std::cin >> vec[i];
		}

		std::sort(vec.begin(), vec.end());
		std::vector<bool> isOut(n, true);

		for(int i = 0; i + 1 < n; i++) {
			if(vec[i] == vec[i+1]) {
				isOut[i] = false;
			} else if (vec[i].size() < vec[i+1].size() && 
					vec[i] == vec[i+1].substr(0, vec[i].size()) && 
					vec[i+1][vec[i].size()] == '/') {
				isOut[i] = false;
			}
		}

		for(int i = 0; i < n; i++) {
			if(isOut[i]) {
				std::cout << "mkdir -p " << vec[i] << std::endl;
			}
		}
		std::cout << std::endl;
	}
}

int main()
{
	// sqlConPoll();
	mkdir_p();
	return 0;
}
