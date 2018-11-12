/*
 * 给你一个N，你想让其变为一个Fibonacci数，
 * 每一步你可以把当前数字X变为X-1或者X+1，
 * 现在给你一个数N求最少需要多少步可以变为Fibonacci数
 * input:15
 * output:2
 */

#include <stdio.h>

int F(int n)
{
    int i = 0, j = 1;
    while(n--){
        j += i;
        i = j - i;
    }
    return i;
}

int main()
{
    int input, n = 0, tmp;
    scanf("%d", &input);

    while(F(n) < input){
        n++;
    }
    tmp = (F(n)-input>input-F(n-1) ? input-F(n-1):F(n)-input);
    printf("%d\n", tmp);
    return 0;
}
