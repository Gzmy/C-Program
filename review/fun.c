#include <stdio.h>
/*
void fun() {
	int tmp = 10;
	int *p = (int *)(*(&tmp+1));
	*(p-1) = 20;
}
*/

void print(int n) {
	if(n > 9) {
		print(n/10);
	}
	printf("%d ", n%10);
}

int myStrlen(const char* p) {
	if(*p == '\0') {
		return 0;
	}
	return 1 + myStrlen(p+1);
}

int factor(int n) {
	if(n <= 1) {
		return 1;
	} else {
		return n * factor(n-1);
	}
}

int fib(int n) {
	int p3, p2, p1;
	p3 = p2 = 1;
	while(n > 2) {
		n -= 1;
		p1 = p2;
		p2 = p3;
		p3 = p1 + p2;
	}
	return p3;
	/*
	if(n <= 2) {
		return 1;
	} else {
		return fib(n-1) + fib(n-2);
	}
	*/
}

int main(int argc, char *argv[], char *envp[])
{
	int i = 0; 
	for(; i < argc; i++) {
		printf("%s\n", argv[i]);
	}


	while(*envp) {
		printf("%s\n", *envp);
		envp++;
	}
	//printf("%d\n", fib(5));
	//printf("%d\n", factor(5));
	//char *p = "woainigzy";
	//printf("%d\n", myStrlen(p));
	//int num = 1234;
	//print(num);
	return 0;
//	int a = 10;
//	fun();
//	printf("a = %d\n", a);
	return 0;
}
