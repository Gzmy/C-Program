#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 小Q的父母要出差N天，走之前给小Q留下了M块巧克力。
// 小Q决定每天吃的巧克力数量不少于前一天吃的一半，
// 但是他又不想在父母回来之前的某一天没有巧克力吃，
// 请问他第一天最多能吃多少块巧克力

int countDay(int num, int day) {
	int sum = 0;
	for(int i = 0; i < day; i++) {
		sum += num;
		num = (num+1) >> 1;
	}
	return sum;
}

int coceFunc(int n, int m) {
	if(n == 1) {
		return m;
	}
	int low = 1, high = m; // 第一天的巧克力是 >=1 <=m
	while(low < high) {
		int mid = (low + high + 1) >> 1; //向上取整
		if(countDay(mid, n) == m) {
			return mid;
		} else if (countDay(mid, n) < m) {
			low = mid;
		} else {
			high = mid;
		}
	}

	return high;
}

void eatChoco() {
	int n, m;
	while(std::cin >> n >> m) {
		std::cout << coceFunc(n, m) << std::endl;
	}
}


int main()
{
	eatChoco();
	return 0;
}
