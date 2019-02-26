//腾讯2017年暑期实习三道

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
//输出需要删除的字符个数。
//https://www.nowcoder.com/test/question/done?tid=21391484&qid=44802#summary


//把一个字符串的大写字母放到字符串的后面，
//各个字符的相对位置不变，且不能申请额外的空间。
//https://www.nowcoder.com/test/question/done?tid=21391484&qid=44803#summary

void processString() {
	std::string str;
	while(std::cin >> str) {
		for(size_t i = 0; i < str.size()-1; i++) {
			for(size_t j = 0; j < str.size()-i-1; j++) {
				if((str[j] > 'A' && str[j] < 'Z') && (str[j+1] < 'A' || str[j+1] > 'Z')) {
					std::swap(str[j], str[j+1]);
				}
			}
		}
		/*
		int start = 0, end = str.size();
		for(int i = start; i < end; i++) {
			if(str[i] > 'a' && str[i] < 'z') {
				std::cout << str[i];
			}
		}
		for(int i = start; i < end; i++) {
			if(str[i] > 'A' && str[i] < 'Z') {
				std::cout << str[i];
			}
		}
		std::cout << std::endl;
		*/
	}
}

//有n个数，两两组成二元组，相差最小的有多少对呢？相差最大呢？
//https://www.nowcoder.com/test/question/done?tid=21391484&qid=44804#summary


void maxAndminNum() {
	int num;
	while(std::cin >> num) {
		std::vector<int> arr(num);
		for(int i = 0; i < num; i++) {
			std::cin >> arr[i];
		}

		if(num == 1 || num == 0) {
			std::cout << "0 0" << std::endl;
			continue;
		}

		std::sort(arr.begin(), arr.end());
		if(arr[0] == arr[num-1]) {
			int sum = num * (num-1) / 2;
			std::cout << sum << " " << sum << std::endl;
			continue;
		}

		int maxNum = std::count(arr.begin(), arr.end(), arr[0]);
		int minNum = std::count(arr.begin(), arr.end(), arr[num-1]);
		int max = maxNum * minNum;
		int minval = arr[1] - arr[0];

		for(int i = 1; i < num; i++) {
			if(arr[i]-arr[i-1] < minval) {
				minval = arr[i] - arr[i-1];
			}
		}

		int min = 0;
		for(int i = 1; i < num; i++) {
			for(int j = i - 1; j >= 0; j--) {
				if(arr[i] - arr[j] == minval) {
					min++;
				} else {
					break;
				}
			}
		}
		std::cout << min << " " << max << std::endl;
	}
}
