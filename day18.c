/*
 * 读入一个字符串str，输出字符串str中的连续最长的数字串
 * 输入 : abcd12345ed125ss123456789
 * 输出 : 123456789
 */

#include <stdio.h>
#include <string.h>

int main()
{
	char buf[255] = {0};
	int len[255] = {0};
	int i = 0;
	scanf("%s", buf);

	int k, sum, max, key;
	for(; i < strlen(buf); i++){
		k = i;
		sum = 0;
		while(buf[i] >= '0' && buf[i] <= '9'){
			i++;
			sum++;
		}
		len[k] = sum;
	}
	max = 0;
	for(i = 0; i < strlen(buf); i++){
		if(max < len[i]){
			max = len[i];
			key = i;
		}
	}
	for(i = 0; i < max; i++){
		printf("%c", buf[key++]);
	}
	printf("\n");
}
