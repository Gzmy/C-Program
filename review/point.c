#include <stdio.h>

int my_strlen(char *str) {
	char *p = str;
	while(*p) {
		p++;
	}
	return p-str;
}

int main()
{
	int arr[10] = {0};
	//int *p1 = &arr;
	int (*p2)[10] = &arr;
	//int arr[10] = {0};

	//printf("%p\n", arr);
	//printf("%p\n", arr+1);
	//printf("%p\n", &arr+1);
	//int *p = "woaini";
	//printf("%d\n", my_strlen(p));
	//int n = 10;
	//char *pc = (char*)&n;
	//int *pi = &n;

	//printf("%p\n", &n);
	//printf("%p\n", pc);
	//printf("%p\n", pc+1);
	//printf("%p\n", pi);
	//printf("%p\n", pi+1);
	//printf("%d\n", sizeof(void*));
	return 0;
}
