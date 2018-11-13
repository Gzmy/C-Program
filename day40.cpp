/*
 * 字符串逆置
 */

#include <iostream>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    string strout[100];
    int len = str.length();
    int i = 0;

    for(; i <= len; i++){
        strout[i] = str.substr(len-i, 1);
    }

    for(i = 0; i <= len; i++){
        cout << strout[i];
    }
    cout << endl;

    return 0;
}
