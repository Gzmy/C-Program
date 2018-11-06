/*
 * 小易是一个数论爱好者，并且对于一个数的奇数约数十分感兴趣.
 * 定义函数f(x)为x最大的奇数约数，x为正整数。 例如:f(44) = 11.
 * 现在给出一个N，需要求出 f(1) + f(2) + f(3).......f(N)
 * 例如： N = 7 
 * f(1) + f(2) + f(3) + f(4) + f(5) + f(6) + f(7) = 1 + 1 + 3 + 1 + 5 + 3 + 7 = 21
 */

#include <stdio.h>

int main()
{
    long input, i, sum = 0;
    scanf("%d", &input);
    while(input){
        for(i = 1; i <= input; i += 2){
            sum += i;
        }
        input /= 2;
    }
    printf("%d\n", sum);
}
