/*
 *	输入数据为一个文件路径
 *	对于每个测试实例，要求输出对应的filename extension
 *	eg
 *		输入：Abc/file.txt
 *		输出：txt
 */

#include <stdio.h>

int main()
{
	char buf[1024];
	while(scanf("%s", buf) != EOF)
	{
		int i;
		for(i = 0; buf[i] != '\0'; i++)
		{
			if(buf[i] == '.')
				break;
		}
		puts(buf+i+1);
	}
}
