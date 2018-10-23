/*
 * 一个数组有 N 个元素，求连续子数组的最大和。
 * 例如：[-1,2,1]，和最大的连续子数组为[2,1]，其和为 3
 */

#include <stdio.h>

int main()
{
	int n, i, max;
	scanf("%d", &n);
	int a[n], b[n];

	for(i = 0; i < n; i++){
		scanf("%d", a+i);
	}

	max = a[0];
	b[0] = a[0];
	for(i = 1; i < n; i++){  //此处是连续子集,可以放到b中
		if(b[i-1] > 0){
			b[i] = a[i] + b[i-1];
		}
		else{
			b[i] = a[i];
		}

		max = max>b[i] ? max:b[i];
	}
	printf("%d\n", max);
	return 0;
}
