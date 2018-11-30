#include <iostream>
#include <string>
using namespace std;

int Add(int x, int y);

//最后一个单词的长度
int main()
{
    cout << Add(5, 6) << endl;
    //string s;
    //while(getline(cin, s)){
    //    cout << s.substr(s.rfind(' ')+1).size() << endl;
    //}
    return 0;
}

//验证一个字符串是否是回文串
class Solution{
public:
    bool isPalind(char c)
    {
        if(c >= '0' && c <= '9' ||
           c >= 'A' && c <= 'Z' ||
           c >= 'a' && c <= 'z'){
            return true;
        }

        return false;
    }

    bool isPalindrome(string s)
    {
        if(s.empty()){
            return true;
        }

        int left = 0;
        int right = s.size()-1;

        while(left < right){
            while(left < right && !isPalind(s[left])){
                left++;
            }

            while(left < right && !isPalind(s[right])){
                right++;
            }

            if((s[left]+32-'a')%32 != (s[right]+32-'a')%32){
                return false;
            }
            left++, right--;
        }

        return true;
    }
};

//整数相加不用+，-，*，/
int Add(int x, int y)
{
    int sum, tmp;
    do{
        sum = x ^ y; //相当于没有进位的加
        tmp = (x & y) << 1; //1+1有进位，相当与找到进位

        x = sum;
        y = tmp;
    }while(tmp);

    return x;
}
