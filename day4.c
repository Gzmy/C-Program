/*
 * 数列的第一项为n，以后各项为前一项的平方根，求数列的前m项的和。
 * 要求精度保留2位小数。
 * 输入 :2 2
 * 输出 :3.41
 */
#include <stdio.h>
#include <math.h>

int main()
{
	int m, n;
	while(scanf("%d %d", &m, &n) != EOF)
	{
		int i;
		double sum = 0, a;
		a = (double)m;
		while(n--)
		{
			sum += a;
			a = sqrt(a);
		}
		printf("%.2lf\n", sum);
	}
	return 0;
}
