/*
 * 水仙花数
 * eg: 153 = 1^3 + 5^3 + 3^3
 */

#include <stdio.h>
#include <math.h>

int main()
{
	int a, b;
	while(scanf("%d %d", &a, &b) != EOF)
	{
		int i, c;
		int flag = 0;
		i = a;
		while(i++<b)
		{
			c = pow(i/100, 3) + pow((i/10)%10, 3) + pow(i%10, 3);
			if(c == i)
			{
				flag++;
				printf("%d, ", c);
			}
		}
		if(flag == 0)
			printf("no\n");
		printf("\n");
	}
	return 0;
}
