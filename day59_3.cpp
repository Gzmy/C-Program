#include <iostream>
#include <vector>
using namespace std;

//leetcode 118 Pascal's Triangle
class Solution{
public:
    vector<vector<int>> generate(int numRows){
        vector<vector<int>> vec;
        if(numRows == 0){
            return vec;
        }

        vec.resize(numRows);
        for(int i = 0; i < numRows; i++){
            vec[i].resize(i + 1);
            vec[i][i] = 1;
            vec[i][0] = 1;
        }

        for(int i = 2; i < numRows; i++){
            for(unsigned long j = 1; j < vec[i].size()-1; j++){
                vec[i][j] = vec[i-1][j] + vec[i-1][j-1];
            }
        }

        return vec;
    }
};
