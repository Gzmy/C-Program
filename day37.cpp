/*
 * 给定一个字符串A，同时给定它的长度n及参数字符数组arg，
 * 请返回替换后的字符串。
 * 保证参数个数大于等于占位符个数。
 * 保证原串由大小写英文字母组成，同时长度小于等于500。
 * "A%sC%sE",7,['B','D','F']
 * 返回："ABCDEF"
 */

#include <iostream>
using namespace std;

class StringFormat{
public:
    string formatString(string A, int n, vector<char> arg, int m){
        int pos = A.find("%s");
        int i = 0;
        string s;
        while(pos != string::npos){
            s = arg[i++];
            A.replace(pos, 2, s, 0, 1);
            pos = A.find("%s");
        }

        while(i < m){
            A += arg[i++];
        }
        return A;
    }
};
