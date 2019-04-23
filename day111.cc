#include <iostream>
#include <string>
#include <vector>
#include <queue>

// nowcoder 走迷宫
// https://www.nowcoder.com/questionTerminal/6276dbbda7094978b0e9ebb183ba37b9?orderByHotValue=1&done=0&pos=10&mutiTagIds=589&onlyReference=false

typedef struct pos {int x, y, level;} pos;

int mostLess(std::vector<std::vector<char>>& vec) {
	const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
	std::queue<pos> que;
	int m = vec.size(), n = vec[0].size();
	std::vector<std::vector<bool>> step(m, std::vector<bool>(n, false));

	pos start{0, 1, 0}, end{9, 8, 0};
	que.push(start);
	step[start.x][start.y] = true;
	while(!que.empty()) {
		pos cur = que.front(), next;
		que.pop();

		for(int i = 0; i < 4; i++) {
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			next.level = cur.level + 1;

			if(next.x == end.x && next.y == end.y) {
				return next.level;
			}

			if(next.x >= 0 && next.x < m && next.y >= 0 && next.y < n\
					&& !step[next.x][next.y] && vec[next.x][next.y] == '.') {
				que.push(next);
				step[next.x][next.y] = true;
			}
		}
	}
	return 0;
}

int main()
{
	std::vector<std::vector<char>> vec(10, std::vector<char>(10));
	while(std::cin >> vec[0][0]) {
		for(int i = 0; i < 10; i++) {
			for(int j = 0; j < 10; j++) {
				if(i == 0 && j == 0) {
					continue;
				}
				std::cin >> vec[i][j];
			}
		}

		std::cout << mostLess(vec) << std::endl;
	}
	return 0;
}
