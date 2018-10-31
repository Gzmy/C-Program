/*
 * 给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，
 * 返回此范围内所有数字的按位与（包含 m, n 两端点）。
 * 输入:[5, 7]
 * 输出:4
 */

#include <stdio.h>

int main()
{
	int m, n;
	int i = 0;
	scanf("%d%d", &m, &n);
	while(m != n){
		m >>= 1;
		n >>= 1;
		++i;
	}

	printf("%d\n", m<<i);
	return 0;
}
