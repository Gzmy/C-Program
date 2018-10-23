/*
 * 统计大写字母的个数
 */

#include <stdio.h>

int main()
{
	char buf[1000];
	int sum = 0, i = 0;
	scanf("%s", buf);
	while(buf[i]){
		if(buf[i] >= 'A' && buf[i] <= 'Z'){
			sum++;
		}
		i++;
	}
	printf("%d\n", sum);
}
