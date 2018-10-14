/*
 *
 */

#include <stdio.h>

int main()
{
	int a, b, i, j;
	int buf[100] = {0};
	int std[100] = {0};
	scanf("%d%d", &a, &b);
	for(i = 0; i < a; i++)
	{
		scanf("%d", buf+i);
	}
	for(j = 0; j < b; j++)
	{
		scanf("%d", std+j);
	}
	int out[200], out_dex = 0;
	i = 0, j = 0;
	while(buf[i] && std[j])
	{
		if(buf[i] < std[j])
		{
			out[out_dex++] = buf[i++];
		}
		else if(buf[i] == std[j])
		{
			out[out_dex++] = buf[i];
			i++,j++;
		}
		else
		{
			out[out_dex++] = std[j++];
		}
	}
	if(buf[i])
	{
		while(buf[i])
		{
			out[out_dex++] = buf[i++];
		}
	}
	else
	{
		while(std[j])
		{
			out[out_dex++] = std[j++];
		}
	}
	for(i = 0; i < out_dex-1; i++)
	{
		printf("%d ", out[i]);
	}
	printf("%d\n", out[i]);
	return 0;
}
