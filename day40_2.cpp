#include <iostream>
using namespace std;

class solution{
public:
    int firstUniqChar(string s)
    {
        int count[256] = {0};
        int len = s.size();
        int i = 0;

        for(; i < len; i++){
            count[s[i]] += 1;
        }

        for(i = 0; i < len; i++){
            if(1 == count[s[i]]){
                return i;
            }
        }

        return -1;
    }
};
