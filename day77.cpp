#include <iostream>
#include <string>
#include <algorithm>

class Solution{
	public:
		std::string ReverseSentence(std::string str) {
			if(str.empty()){
				return str;
			}

			int start = 0;
			for(int i = 0; i < str.size(); i++){
				if(str[i] == ' '){
					std::reverse(str.begin()+start, str.begin()+i);
					start = i+1;
				}
				if(i == str.size()-1){
					std::reverse(str.begin()+start, str.end());
				}
			}
			std::reverse(str.begin(), str.end());
			return str;
		}
};
