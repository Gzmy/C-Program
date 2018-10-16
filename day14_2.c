/*
 * 输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
 * 例如，输入”They are students.”和”aeiou”，
 * 则删除之后的第一个字符串变成”Thy r stdnts.”
 *
 */

#include <stdio.h>

int main()
{
	char buf[20], std[20];
	int i, j;
	gets(buf);
	gets(std);

	for(i = 0; buf[i]; i++)
	{
		for(j = 0; std[j]; j++)
		{
			if(buf[i] == std[j])
				buf[i] = '-';
		}
	}
	for(i = 0; buf[i]; i++)
	{
		if(buf[i] != '-')
			printf("%c", buf[i]);
	}
	
	return 0;
}
