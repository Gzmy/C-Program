#include <stdio.h>
#include <string.h>

int main()
{
	char buf[30], std[30];
	while(scanf("%s%s", buf, std) != EOF)
	{
		int i = 0, flag = 0;
		while(buf[i])
		{
			if(buf[i] >= '0' && buf[i] <= '9')
			{
				i++;
				continue;
			}
			else
			{
				flag++;
				break;
			}
		}
		i = 0;
		while(std[i])
		{
			if(std[i] >= '0' && std[i] <= '9')
			{
				i++;
				continue;
			}
			else
			{
				flag++;
				break;
			}
		}
		if(flag == 0)
		{
			printf("%u\n", atoll(buf) + atoll(std));
		}
	}
	return 0;
}
