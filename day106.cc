#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int pathOfAB(std::string A, std::string B) {
	if(A.empty() || B.empty()) {
		return std::max(A.size(), B.size());
	}

	int lenA = A.size();
	int lenB = B.size();
	std::vector<std::vector<int> > vec(lenA+1, std::vector<int>(lenB+1, 0));

	for(int i = 0; i <= lenA; i++) {
		vec[i][0] = i;
	}

	for(int i = 0; i <= lenB; i++) {
		vec[0][i] = i;
	}

	for(int i = 1; i <= lenA; i++) {
		for(int j = 1; j <= lenB; j++) {
			if(A[i-1] == B[j-1]) {
				vec[i][j] = 1 + std::min(vec[i-1][j], vec[i][j-1]);
				vec[i][j] = std::min(vec[i][j], vec[i-1][j-1]);
			} else {
				vec[i][j] = 1 + std::min(vec[i-1][j], vec[i][j-1]);
				vec[i][j] = std::min(vec[i][j], vec[i-1][j-1] + 1);
			}
		}
	}

	return vec[lenA][lenB];
}

int main()
{
	std::string A, B;
	while(std::cin >> A >> B) {
		std::cout << pathOfAB(A, B) << std::endl;
	}
	return 0;
}
