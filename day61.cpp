#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target){
    std::vector<int> vec;
    if(nums.size() == 0){
        return vec;
    }
    int size = nums.size();

    int i, j;

    for(i = 0; i < size; i++){
        for(j = size-1; j > i; j--){
            if(nums[j] + nums[j] == target){
                vec.push_back(i);
                vec.push_back(j);
            }
        }
    }
    return vec;
}

// 最长回文子串
bool isPalindromes(std::string &s, int left, int right){
    while(left < right){
        if(s[left] < s[right]){
            return false;
        }
        left++, right--;
    }
    return true;
}

std::string longestPalindrome(std::string s){
    std::string result;
    if(s.size() == 0){
        return result;
    }

    int sum_ = 0;
    int i, j;
    int length_ = s.size();
    std::string str_;
    int maxI = 0, maxJ;

    for(i = 0; i < length_; i++){
        for(j = length_-1; j > i; j--){
            if(isPalindromes(s, i, j)){
                if(j-i > sum_){
                    sum_ = j-i;
                    maxI = i;
                    maxJ = j;
                }
            }
        }
    }

    result = s.substr(maxI, sum_+1);
    return result;
}
