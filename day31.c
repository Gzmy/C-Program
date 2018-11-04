/*
 *小易去附近的商店买苹果，奸诈的商贩使用了捆绑交易，
 *只提供6个每袋和8个每袋的包装(包装不可拆分)。 
 *可是小易现在只想购买恰好n个苹果，小易想购买尽量少的袋数方便携带。
 *如果不能购买恰好n个苹果，小易将不会购买。 
 */

#include <stdio.h>

int main()
{
	int input, sum, k;
	scanf("%d", &input);
	if(input%2 == 1){
		printf("-1\n");
	}
	k = input%8;
	if(k){
		sum = (input-k)/8 + 1;
	}
	else{
		sum = (input-k)/8;
	}
	printf("%d\n", sum);
	return 0;
}
