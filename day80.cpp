#include <iostream>

class Solution{
	public:
		//正则表达式匹配
		bool match(char* str, char* pattern){
			if(pattern[0] == 0 && str[0] == 0){
				return true;
			}

			if(pattern[0] != 0 && pattern[1] == '*'){
				if(match(str, pattern+2)){
					return true;
				}
			}

			if((pattern[0] == '.' && str[0]) || str[0] == pattern[0]){
				if(match(str+1, pattern+1)){
					return true;
				}
				if(pattern[1] == '*' && match(str+1, pattern)){
					return true;
				}
			}

			return false;
		}
};
