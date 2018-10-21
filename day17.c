/*
 *	输出n个整数里面的最小的k个数
 */

#include <stdio.h>
#include <string.h>

#define MAX 100
int main()
{
	int str[MAX+1] = {0};
	int i = 0, j;
	int len = 0;
	while(scanf("%d", str+i) != EOF){
		i++;
	}
	len = i - 1;
	int k = str[i - 1];
	for(i = 0; i < len; i++){
		for(j = 0; j < len-1-i; j++){
			if(str[j] > str[j+1]){
				int tmp = str[j];
				str[j] = str[j+1];
				str[j+1] = tmp;
			}
		}
	}
	for(i = 0; i < k; i++){
		printf("%d ", str[i]);
	}
	printf("\n");
}
