#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>

int findMinNumToFib() {
	int N;
	std::cin >> N;
	int f0 = 0, f1 = 1, f;
	int max = 0, min = 0;
	while(1) {
		f = f0 + f1;
		f0 = f1;
		f1 = f;
		if(f < N) {
			min = N - f;
		} else {
			max = f - N;
			break;
		}
	}

	return std::min(max, min);
}

//合法括号判别
bool chkParenthesis(std::string A, int n) {
	std::stack<char> s;
	for(int i = 0; i < n; i++) {
		if(A[i] != '(' && A[i] != ')') {
			return false;

		}

		if(A[i] == '(') {
			s.push(A[i]);

		}

		if(A[i] == ')' && !s.empty()) {
			s.pop();

		}
	}

	if(s.empty()) {
		return true;

	} else {
		return false;

	}
}

int main()
{
	std::cout << findMinNumToFib() << std::endl;
	return 0;
}
