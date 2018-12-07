#include <iostream>
using namespace std;

class Solution{
public:
    bool duplicate(int numbers[], int length, int* duplication){
        if(numbers == NULL || length <= 0){
            return false;
        }

        for(int i = 0; i < length; i++){
            if(numbers[i] < 0 || numbers[i] > length-1){
                return false;
            }
        }

        for(int i = 0; i < length; i++){
            while(numbers[i] != i){
                if(numbers[i] == numbers[numbers[i]]){
                    *duplication = numbers[i];
                    return true;
                }

                swap(numbers[i], numbers[numbers[i]]);
            }
        }

        return false;
    }

    //数组中出现次数超过一半的数字
    bool isLengthHalf(vector<int> &nums, int result){
        int times = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == result){
                times++;
            }
        }

        if(times * 2 <= nums.size()){
            return false;
        }else{
            return true;
        }
    }

    int MoreThanHalfNum_Solution(vector<int> numbers){
        if(numbers.size() == 0){
            return -1;
        }

        int result = numbers[0];
        int times = 1;
        for(int i = 1; i < numbers.size(); i++){
            if(times == 0){
                result = numbers[i];
                times = 1;
            }

            if(result == numbers[i]){
                times++;
            }else{
                times--;
            }
        }

        if(isLengthHalf(numbers, times)){
            return result;
        }else{
            return 0;
        }
    }
};
