/*
 * 对于一个整数X，定义操作rev(X)为将X按数位翻转过来，并且去除掉前导0。例如:
 * 如果 X = 123，则rev(X) = 321;
 * 如果 Y = 100，则rev(Y) = 1.
 * 现在给出整数x和y,要求rev(rev(x) + rev(y)) = 223
 */

#include <stdio.h>

int rev(int n)
{
    int dig, sum = 0;
    while(n){
        dig = n % 10;
        sum = sum*10 + dig;
        n /= 10;
    }
    return sum;
}

int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d\n", rev(rev(x) + rev(y)));
}
