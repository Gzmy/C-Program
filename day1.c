/*
 * 给定一个句子(只包含字母和空格),将句子中的单词位置反转，
 * 单词用空格分割, 单词之间只有一个空格，前后没有空格。 
 * 比如：（1） “hello xiao mi”-> “mi xiao hello”
 *
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
	char arr[1000];
	int len, i, j;
	ssize_t s = read(0, arr, sizeof(arr)-1);
	arr[s] = 0;
	len = strlen(arr);
	for(i = len-1; i >= 0; i--)
	{
		if(arr[i] == ' ')
		{
			for(j = i+1; arr[j] != '\0'&& arr[j] != ' '; j++)
				printf("%c", arr[j]);

			printf(" ");
		}
	}
	i = 0;
	while(arr[i] != ' ')
		i++;
	for(j = 0; j < i; j++)
		printf("%c", arr[j]);
	return 0;
}
