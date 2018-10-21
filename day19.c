/*
 * 输入一个正整数n,求n!(即阶乘)末尾有多少个0？
 * 比如: n = 10; n! = 3628800,所以答案为2
 */

#include <stdio.h>

int sev(int n)
{
	if(n == 1){
		return 1;
	}
	else
		return n * sev(n-1);
}

int main()
{
	int n;
	int flag = 0;
	scanf("%d", &n);
	int sum = sev(n);
	while(sum){
		int tmp = sum % 10;
		if(tmp == 0)
			flag++;
		sum /= 10;
	}
	printf("%d\n", flag);
}
