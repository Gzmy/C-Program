/*
 *                   替换空格
 * 请实现一个函数，将一个字符串中的每个空格替换成“%20”。
 * 例如，当字符串为We Are Happy.
 * 则经过替换之后的字符串为We%20Are%20Happy。
 * 在一个数组里从后往前复制
 *
 */

#include <stdio.h>

void Replacespace(char arr[], int len)
{
	int i = 0, num = 0, spnum = 0, realnum;

	if(arr == NULL || len < 0)
		return;

	while(arr[i])
	{
		num++;
		if(arr[i] == ' ')
			spnum++;
		i++;
	}

	realnum = num + spnum*2;
	if(realnum > len)
		return;

	while(num < realnum && realnum > 0)
	{
		if(arr[num] == ' ')
		{
			arr[realnum--] = '0';
			arr[realnum--] = '2';
			arr[realnum--] = '%';
		}
		else
		{
			arr[realnum--] = arr[num];
		}
		num--;
	}
}

int main()
{
	char arr[30] = "We are happy.";
	Replacespace(arr, 30);
	printf("%s\n", arr);
	return 0;
}
