#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//字符流中第一个不重复的字符
class Solution{
	private:
		std::string s;
		int array[256] = {0};
	public:
		void Insert(char ch){
			s.push_back(ch);
			array[ch]++;
		}

		char FirstAppearingOnce(){
			for(int i = 0; i < s.size(); i++){
				if(array[s[i]] == 1){
					return s[i];
				}
			}
			return '#';
		}
};

//数据流中的中位数
class solution{
	public:
		std::vector<double> vec;
		void Insert(int num){
			vec.push_back(num);
		}

		double getMedian(){
			double result;
			std::sort(vec.begin(), vec.end());
			if(vec.size() % 2 == 1.0){
				result = vec[(vec.size()-1) / 2];
			}else{
				result = (vec[vec.size()/2] + vec[vec.size()/2 - 1]) / 2;
			}

			return result;
		}
};
