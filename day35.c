/*
 * 写出一个程序，接受一个十六进制的数值字符串，
 * 输出该数值的十进制
 * input:  0xA
 * output: 10
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char input[101];
    while(scanf("%s", input) != EOF){
        int len = strlen(input);
        long ans = 0;
        long bit = 1;
        int i = 0;
        for(i = len-1; i >= 2; i--){
            if(input[i] >= 'A' && input[i] <= 'F'){
                ans += (input[i]-'A' + 10) * bit;
            }
            else{
                ans += (input[i]-'0') * bit;
            }
            bit *= 16;
        }
        printf("%ld\n", ans);
    }
    return 0;
}
