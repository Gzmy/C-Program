/*编写算法判断一个数是不是"快乐数"
 * 
 * 一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和
 * 然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。
 * 如果可以变为 1，那么这个数就是快乐数。
 * 任何不快乐数,都会进入 4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4 的循环中。
 * 
 * eg:19是.
 */
#include <math.h>

int do_add(int sum)
{
    int tmp = 0;
    while(sum){
        tmp += pow(sum%10, 2);
        sum /= 10;
    }
    return tmp;
}

bool ishappy(int n)
{
    if(n == 1){
        return true;
    }
    else if(n < 1){
        return false;
    }

    int tmp = n;
    while(1){
        tmp = do_add(tmp);
        if(tmp == 1){
            return true;
        }
        if(tmp == 89){
            return false;
        }
    }
}
