/*
 *					统计字符
 * 给定一个英文字符串,请写一段代码找出这个字符串中首先出现三次的那个英文字符(需要区分大小写)。
 * 输入数据一个字符串，包括字母,数字等。输出首先出现三次的那个英文字符
 * eg:
 *		输入:Have you ever gone shopping and
 *		输出:h
 */

#include <stdio.h>
#include <string.h>

int main()
{
	int std[1000], i;
	char buf[1024];
	ssize_t s = read(0, buf, sizeof(buf)-1);
	buf[s] = 0;
	for(i = 0; buf[i] != 0; i++)
	{
		if(((buf[i] >= '0'&&buf[i] <= '9') || (buf[i] >= 'a'&&buf[i] <= 'z') || (buf[i] >= 'A'&&buf[i] <= 'Z')) && ++std[buf[i]] == 3)
		{
			printf("%c\n", buf[i]);
			break;
		}
	}
	//int std[1000], i;
	//char buf[1024], c;
	//for(i = 0; (c=getchar()) != '\n'; ){
	//	buf[i++] = c;
	//}
	//buf[i] = '\0';

	////printf("%s", buf);
	//for(i = 0; buf[i]; i++)
	//{
	//	if((buf[i] >= 'a'&& buf[i] <= 'z') || (buf[i] >= 'A' && buf[i] <= 'Z') || (buf[i] >= '0' && buf[i] <= '9'))
	//	{
	//		std[buf[i]]++;
	//		if(std[buf[i]] == 3)
	//		{
	//			printf("%c\n", buf[i]);
	//			break;
	//		}
	//	}
	//}
	return 0;
}
