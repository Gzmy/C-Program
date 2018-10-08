/*
 *			身份证分组
 *	输入数据有多行，每一行是一个输入过程中的身份证号,
 *	输出分组后的字符串
 *	eg : 502104198803308324
 *		 502104 19880330 8324
 */

#include <stdio.h>

int main()
{
	char buf[20];
	int i = 0;
	while(scanf("%s", buf) != EOF)
	{
		while(buf[i])
		{
			if(i == 6 || i == 14)
				printf(" ");
			printf("%c", buf[i]);
			i++;
		}
	}
	return 0;
}
