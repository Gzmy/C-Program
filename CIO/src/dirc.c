/*hello user*/
//字典查找
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


typedef struct
{
	char yy[50];
	char hy[50];
	char cy[6];
}DICT_T;

DICT_T words[8000];
int count;

void load_file()
{
	FILE *fp = fopen("dictionary.txt", "r");
	if (fp == NULL) perror("fopen") ,exit(1);

	while ( !feof(fp) )
	{
		fscanf(fp, "%s\t%s\t%s", words[count].yy, words[count].hy, words[count].cy);
		count++;
	}

	fclose(fp);
}

int bin_search( const char *buf )
{
	int left = 0;
	int right = count - 1;

	while (left <= right)
	{
		int mid = left + (right - left)/2;

		if (strcmp(buf, words[mid].yy) == 0)
			return mid;
		else if(strcmp(buf, words[mid].yy) < 0)
			right = mid - 1;
		else
			left = mid + 1;
	}

	return -1;
}

int main()
{
	load_file();
	char buf[50];
	int num;

	do
	{
		printf("请输入要查找的单词:\n");
		scanf("%s", buf);
		if((num = bin_search(buf)) == -1)
		{
			printf("没有单词\n");
		}
		else
		{
			printf("%s : %s %s", words[num].yy, words[num].hy, words[num].cy);
		}
	} while(1);

	return 0;
}
