/*
 * 小易有一个圆心在坐标原点的圆，小易知道圆的半径的平方。
 * 小易认为在圆上的点而且横纵坐标都是整数的点是优雅的，
 * 小易现在想寻找一个算法计算出优雅的点的个数，请你来帮帮他。
 * 例如：半径的平方如果为25
 * 优雅的点就有：(+/-3, +/-4), (+/-4, +/-3), (0, +/-5) (+/-5, 0)，一共12个点。
 */

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int sum = 0, i, x, tmp;
    cin>>x;
    tmp = (int)sqrt(x);
    if(tmp*tmp == x){
        sum += 4;
        tmp--;
    }

    for(i = tmp; i > 0; i--){
        int ret = (int)sqrt(x-i*i);
        if(ret*ret + i*i == x){
            sum += 4;
        }
    }
    cout << sum << endl;
    return 0;
}
