/*
 * 给你六种面额1、5、10、20、50、100元的纸币，假设每种币值的数量都足够多，
 * 编写程序求组成N元（N为0-10000的非负整数）的不同组合的个数。
 * 输入：5
 * 输出：2
 */

#include <stdio.h>

int main()
{
	int input;
	while(scanf("%d", &input) != EOF)
	{
		int money[6] = {1, 5, 10, 20, 50, 100};
		int i, j;
		long long an[1000];
		for(i = 0; i <= input; i++)
			an[i] = 1;
		for(i = 1; i < 6; i++)
		{
			for(j = 1; j <= input; j++)
			{
				if(j >= money[i])
					an[j] += an[j - money[i]];
			}
		}
		printf("%ld\n", an[input]);
	}
	return 0;
}
