#include <iostream>
#include <string>

class Solution{
	public:
		std::string LeftRotateString(std::string str, int n) {
			int len = str.size();
			if(str.empty() || n%len == 0){
				return str;
			}

			std::string s1 = str.substr(0, n%len);
			std::string s2 = str.substr(n%len);

			return s2+s1;
		}
};
