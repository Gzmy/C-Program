#include <iostream>
#include <string>

// https://www.nowcoder.com/questionTerminal/9f6b8f6ec26d44cfb8fc8c664b0edb6b
void passHard() {
	std::string str;
	while(std::getline(std::cin, str)) {
		std::string res;
		for(size_t i = 0; i < str.size(); i++) {
			if(str[i] == ' ') {
				res.push_back(str[i]);
			} else if (str[i] - 'A' >= 5) {
				res.push_back(str[i] - 5);
			} else {
				res.push_back(str[i] + 21);
			}
		}

		std::cout << res << std::endl;
	}
}

int main()
{
	passHard();
	return 0;
}
